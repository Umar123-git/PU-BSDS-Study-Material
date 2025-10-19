data = []
domain_count = {}

n = 0
while n <= 0:
    n = int(input("Enter number of email addresses: "))
    if n <= 0:
        print("Invalid input, try again.")

i = 1
while i <= n:
    print(f"\n-------------------- Email {i} --------------------")
    email = input("Enter email address: ")

   
    if "@" in email and "." in email.split("@")[-1]:
        domain = email.split("@")[-1]
        data.append([email, domain])

       
        if domain in domain_count:
            domain_count[domain] += 1
        else:
            domain_count[domain] = 1
    else:
        print("Invalid email format. Skipping this entry.")
    
    i += 1


print("\n-------------------- Email Summary --------------------")
print("Total valid emails:", len(data))

for domain in domain_count:
    print(f"Users with domain '{domain}': {domain_count[domain]}")