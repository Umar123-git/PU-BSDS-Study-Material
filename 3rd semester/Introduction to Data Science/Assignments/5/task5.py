users = {}
n = 0

while n <= 0:
    n = int(input("Enter number of users: "))
    if n <= 0:
        print("Invalid input, try again.")

for i in range(1, n + 1):
    name = input(f"\nEnter name of user {i}: ")
    friends = input("Enter comma-separated friend names: ").split(",")
    friends = [f.strip() for f in friends if f.strip() != name] 
    users[name] = set(friends)


user_names = list(users.keys())

for i in range(len(user_names)):
    for j in range(i + 1, len(user_names)):
        u1 = user_names[i]
        u2 = user_names[j]

        print(f"\n-------------------- {u1} & {u2} --------------------")

        mutual = users[u1] & users[u2]
        unique_u1 = users[u1] - users[u2]
        unique_u2 = users[u2] - users[u1]

        print("Mutual friends:", list(mutual) if mutual else "None")
        print(f"Unique to {u1}:", list(unique_u1) if unique_u1 else "None")
        print(f"Unique to {u2}:", list(unique_u2) if unique_u2 else "None")

       
        suggestions_for_u1 = unique_u2 - {u1}
        suggestions_for_u2 = unique_u1 - {u2}

        print(f"Suggested friends for {u1}:", list(suggestions_for_u1) if suggestions_for_u1 else "None")
        print(f"Suggested friends for {u2}:", list(suggestions_for_u2) if suggestions_for_u2 else "None")