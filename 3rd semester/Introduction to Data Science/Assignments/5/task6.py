subtotal = 0
items = int(input("Enter number of items ordered: "))

i = 1
while i <= items:
    print(f"\n-------------------- Item {i} --------------------")
    name = input("Enter item name: ")
    price = float(input("Enter item price: "))
    subtotal += price
    i += 1

print("\n-------------------- Billing --------------------")
print("Subtotal =", subtotal)


tax_rate = 0.08  # 8% tax
tax = subtotal * tax_rate
print("Tax (8%) =", round(tax, 2))


print("\nRate the service quality:")
print("1. Poor (5%)")
print("2. Average (10%)")
print("3. Good (15%)")
print("4. Excellent (20%)")

choice = int(input("Enter your choice (1-4): "))
tip_rate = 0

if choice == 1:
    tip_rate = 0.05
elif choice == 2:
    tip_rate = 0.10
elif choice == 3:
    tip_rate = 0.15
elif choice == 4:
    tip_rate = 0.20
else:
    print("Invalid choice. Defaulting to 10% tip.")
    tip_rate = 0.10

tip = subtotal * tip_rate
print("Tip =", round(tip, 2))


total = subtotal + tax + tip
print("\nFinal Total =", round(total, 2))