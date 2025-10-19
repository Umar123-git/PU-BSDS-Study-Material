expenses = []
category_totals = {}
largest_expense = ["", 0]
total_spent = 0

budget = float(input("Enter your daily budget: "))
n = int(input("Enter number of expenses: "))

i = 1
while i <= n:
    print(f"\n-------------------- Expense {i} --------------------")
    name = input("Enter expense name: ")
    category = input("Enter category (e.g. food, travel, bills): ").lower()
    amount = float(input("Enter amount spent: "))
    expenses.append([name, category, amount])
    total_spent += amount

    if category in category_totals:
        category_totals[category] += amount
    else:
        category_totals[category] = amount

    if amount > largest_expense[1]:
        largest_expense = [name, amount]

    i += 1

print("\n-------------------- Expense Summary --------------------")
for cat in category_totals:
    print(f"Total spent on {cat}: {category_totals[cat]}")

print("Total spent today:", total_spent)
if total_spent > budget:
    print("Warning: Spending exceeded your budget!")
else:
    print("Good job! Spending is within your budget.")

print("Largest expense:", largest_expense[0], "with amount =", largest_expense[1])