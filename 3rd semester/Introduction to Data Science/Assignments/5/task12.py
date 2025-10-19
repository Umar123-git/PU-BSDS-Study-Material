data = []
total_calories = 0
total_time = 0
activity_types = set()

n = 0
while n <= 0:
    n = int(input("Enter number of users: "))
    if n <= 0:
        print("Invalid input, try again.")

i = 1
while i <= n:
    print(f"\n-------------------- User {i} --------------------")
    name = input("Enter user name: ")
    activities = int(input("Enter number of activities: "))

    j = 1
    while j <= activities:
        print(f"\nActivity {j} for {name}")
        activity = input("Enter activity type (e.g. running, cycling): ").lower()
        time = float(input("Enter workout time in minutes: "))
        calories = float(input("Enter calories burned: "))
        data.append([name, activity, time, calories])
        total_calories += calories
        total_time += time
        activity_types.add(activity)
        j += 1

    i += 1

print("\n-------------------- Fitness Summary --------------------")
print("Total calories burned:", total_calories)
print("Average workout time:", round(total_time / len(data), 2), "minutes")
print("Unique activity types:", list(activity_types))