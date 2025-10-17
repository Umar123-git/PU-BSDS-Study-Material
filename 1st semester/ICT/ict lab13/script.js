document.getElementById("add-task-button").addEventListener("click", function() {
const taskInput = document.getElementById("task-input");
const taskList = document.getElementById("task-list");
if (taskInput.value.trim() !== "") {
const li = document.createElement("li");
li.textContent = taskInput.value;
taskList.appendChild(li);
 taskInput.value = "";
 } else {
 alert("Please enter a task!");
 }});
