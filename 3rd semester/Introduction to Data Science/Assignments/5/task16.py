transactions = []

def add_transaction():
    print("\n-------------------- New Transaction --------------------")
    date = input("Enter transaction date (DD-MM-YYYY): ")
    t_type = input("Enter transaction type (income/expense): ").lower()
    amount = float(input("Enter amount: "))
    category = input("Enter category (e.g. sales, rent, supplies): ").lower()
    transactions.append([date, t_type, amount, category])

def total_summary():
    summary = {}
    for t in transactions:
        cat = t[3]
        amt = t[2]
        if cat in summary:
            summary[cat] += amt
        else:
            summary[cat] = amt
    return summary

def highest_expense():
    max_expense = ["", 0, ""]
    for t in transactions:
        if t[1] == "expense" and t[2] > max_expense[1]:
            max_expense = [t[3], t[2], t[0]]
    return max_expense

def generate_report():
    print("\n-------------------- Financial Summary Report --------------------")
    print("Total transactions recorded:", len(transactions))
    
    summary = total_summary()
    for cat in summary:
        print(f"Total for {cat}: {summary[cat]}")

    high = highest_expense()
    if high[1] > 0:
        print(f"Highest expense: {high[0]} of {high[1]} on {high[2]}")
    else:
        print("No expenses recorded.")

# Main loop
n = int(input("Enter number of transactions to record: "))
i = 1
while i <= n:
    add_transaction()
    i += 1

generate_report()