import gradio as gr
import os
import requests

GROQ_API_KEY = os.environ.get("GROQ_API_KEY")
GROQ_API_URL = "https://api.groq.com/openai/v1/chat/completions"
MODEL_NAME = "llama-3.1-8b-instant"



SYSTEM_PROMPT = """
You are DataMentor AI, a professional Data Science career mentor.
Guide students in Data Science, AI, and Machine Learning.
Be practical, clear, and motivating.
"""

def query_groq(user_message, chat_history, mode, max_tokens, temperature):
    headers = {
        "Authorization": f"Bearer {GROQ_API_KEY}",
        "Content-Type": "application/json"
    }

    messages = [
        {"role": "system", "content": SYSTEM_PROMPT},
        {"role": "system", "content": f"Guidance Type: {mode}"}
    ]

    # chat_history is now a list of dicts [{"role": "user", "content": "..."}, ...]
    # Sanitize: Groq API only accepts 'role' and 'content'
    for msg in chat_history:
        if isinstance(msg, dict) and "role" in msg and "content" in msg:
            messages.append({
                "role": msg["role"],
                "content": msg["content"]
            })

    messages.append({"role": "user", "content": user_message})

    response = requests.post(
        GROQ_API_URL,
        headers=headers,
        json={
            "model": MODEL_NAME,
            "messages": messages,
            "temperature": temperature,
            "max_tokens": max_tokens
        }
    )

    if response.status_code == 200:
        return response.json()["choices"][0]["message"]["content"]
    else:
        return f"Error {response.status_code}: {response.text}"

def respond(user_message, chat_history, mode, max_tokens, temperature):
    bot_reply = query_groq(user_message, chat_history, mode, max_tokens, temperature)

    chat_history.append({"role": "user", "content": user_message})
    chat_history.append({"role": "assistant", "content": bot_reply})

    return "", chat_history

css = """
@import url('https://fonts.googleapis.com/css2?family=Inter:wght@300;400;600;700&display=swap');

:root {
    --primary: #6366f1;
    --primary-hover: #4f46e5;
    --bg-dark: #0f172a;
    --card-bg: #1e293b;
    --border: #334155;
    --text-main: #f8fafc;
    --text-muted: #94a3b8;
}

body, .gradio-container { 
    background-color: var(--bg-dark) !important; 
    font-family: 'Inter', sans-serif !important;
    color: var(--text-main) !important;
}

/* Premium Header */
.header-section {
    text-align: center;
    padding: 40px 20px;
    background: radial-gradient(circle at center, #1e293b 0%, #0f172a 100%);
    border-bottom: 1px solid var(--border);
    margin-bottom: 30px;
    border-radius: 0 0 24px 24px;
}
.header-title {
    font-size: 3rem;
    font-weight: 800;
    letter-spacing: -0.025em;
    background: linear-gradient(135deg, #818cf8 0%, #c084fc 100%);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    margin: 0;
}
.header-badge {
    font-size: 0.75rem;
    vertical-align: middle;
    background: rgba(74, 222, 128, 0.1);
    color: #4ade80;
    padding: 4px 12px;
    border-radius: 9999px;
    border: 1px solid rgba(74, 222, 128, 0.2);
    margin-left: 10px;
    text-transform: uppercase;
    font-weight: 700;
}

/* Sidebar Styling */
.sidebar-box {
    background: var(--card-bg);
    border: 1px solid var(--border);
    border-radius: 20px;
    padding: 24px;
    box-shadow: 0 10px 15px -3px rgba(0, 0, 0, 0.1);
}
.sidebar-label {
    color: var(--text-muted);
    font-size: 0.875rem;
    font-weight: 600;
    margin-bottom: 16px;
    display: block;
}

/* Premium Buttons */
.mode-btn {
    background: #334155 !important;
    border: 1px solid #475569 !important;
    color: #e2e8f0 !important;
    margin-bottom: 12px !important;
    border-radius: 12px !important;
    transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1) !important;
    text-align: left !important;
    padding: 12px 16px !important;
    font-weight: 500 !important;
}
.mode-btn:hover {
    background: #475569 !important;
    transform: translateX(4px);
    border-color: var(--primary) !important;
}
.mode-btn.active {
    background: linear-gradient(135deg, #6366f1 0%, #a855f7 100%) !important;
    border: none !important;
    color: white !important;
    box-shadow: 0 4px 12px rgba(99, 102, 241, 0.3);
}

/* Chatbot Customization */
#chatbot {
    background: var(--card-bg) !important;
    border: 1px solid var(--border) !important;
    border-radius: 20px !important;
    height: 600px !important;
    box-shadow: 0 20px 25px -5px rgba(0, 0, 0, 0.1);
}
.message.user {
    background: var(--primary) !important;
    color: white !important;
    border-radius: 18px 18px 2px 18px !important;
}
.message.bot {
    background: #334155 !important;
    color: var(--text-main) !important;
    border-radius: 18px 18px 18px 2px !important;
}

/* Input Area */
.input-row {
    margin-top: 20px;
    gap: 12px;
}
.input-box {
    background: var(--card-bg) !important;
    border: 1px solid var(--border) !important;
    border-radius: 14px !important;
    color: white !important;
}
.send-btn {
    border-radius: 14px !important;
    font-weight: 600 !important;
}
"""

with gr.Blocks() as demo:
    # Premium Header
    gr.HTML(f"""
        <div class="header-section">
            <h1 class="header-title">DataMentor AI <span class="header-badge">Premium Pro</span></h1>
            <p style="color: #94a3b8; margin-top: 10px; font-size: 1.1rem;">Expert Data Science Mentorship Powered by Llama 3.1</p>
        </div>
    """)

    with gr.Row():
        # Sidebar
        with gr.Column(scale=1):
            with gr.Column(elem_classes="sidebar-box"):
                gr.Markdown("<span class='sidebar-label'>MENTORSHIP FOCUS</span>")
                
                mode_state = gr.State("Career Roadmap")
                
                # Visual indicator of current mode
                mode_display = gr.Textbox(
                    value="Career Roadmap", 
                    label="Active Focus", 
                    interactive=False,
                    container=False
                )
                
                gr.Markdown("<div style='margin: 20px 0; border-top: 1px solid #334155;'></div>")
                
                btn_career = gr.Button("🧭 Career Roadmap", elem_classes="mode-btn")
                btn_skill = gr.Button("🧠 Skill Learning", elem_classes="mode-btn")
                btn_project = gr.Button("💡 Project Ideas", elem_classes="mode-btn")
                btn_interview = gr.Button("👔 Interview Prep", elem_classes="mode-btn")
                
                gr.Markdown("<div style='margin: 20px 0; border-top: 1px solid #334155;'></div>")
                
                response_length = gr.Slider(
                    minimum=128, 
                    maximum=4096, 
                    value=1024, 
                    step=128, 
                    label="Response Length",
                    info="Max tokens for the response"
                )

                temperature = gr.Slider(
                    minimum=0.0,
                    maximum=1.0,
                    value=0.7,
                    step=0.1,
                    label="Response Creativity",
                    info="Higher values make the output more random"
                )
                
                gr.Markdown("<div style='margin: 20px 0; border-top: 1px solid #334155;'></div>")
                clear_btn = gr.Button("🗑️ Reset Session", variant="stop", elem_classes="send-btn")

        # Main Chat Area
        with gr.Column(scale=3):
            chatbot = gr.Chatbot(
            label="Mentorship Session",
            elem_id="chatbot",
            avatar_images=(None, "https://cdn-icons-png.flaticon.com/512/6134/6134346.png")
        )
            
            with gr.Row(elem_classes="input-row"):
                msg = gr.Textbox(
                    placeholder="Ask your mentor anything about Data Science...",
                    show_label=False,
                    scale=4,
                    elem_classes="input-box",
                    container=False,
                    autofocus=True
                )
                submit_btn = gr.Button("Send ➤", variant="primary", scale=1, elem_classes="send-btn")

    # Event Handling
    def set_mode(new_mode):
        return new_mode, new_mode

    btn_career.click(set_mode, inputs=[gr.State("Career Roadmap")], outputs=[mode_state, mode_display])
    btn_skill.click(set_mode, inputs=[gr.State("Skill Learning")], outputs=[mode_state, mode_display])
    btn_project.click(set_mode, inputs=[gr.State("Project Ideas")], outputs=[mode_state, mode_display])
    btn_interview.click(set_mode, inputs=[gr.State("Interview Prep")], outputs=[mode_state, mode_display])

    # Chat interactions
    msg.submit(respond, [msg, chatbot, mode_state, response_length, temperature], [msg, chatbot])
    submit_btn.click(respond, [msg, chatbot, mode_state, response_length, temperature], [msg, chatbot])
    
    # Clear chat
    clear_btn.click(lambda: ([], ""), None, [chatbot, msg])

if __name__ == "__main__":
    demo.launch(
        debug=True,
        css=css,
        theme=gr.themes.Soft(primary_hue="indigo", neutral_hue="slate")
    )

