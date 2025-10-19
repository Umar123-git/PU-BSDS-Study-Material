data = []
total_distance = 0

n = 0
while n <= 0:
    n = int(input("Enter number of delivery points: "))
    if n <= 0:
        print("Invalid input, try again.")

i = 1
while i <= n:
    print(f"\n-------------------- Delivery Point {i} --------------------")
    location = input("Enter location name: ")
    time = input("Enter delivery time (HH:MM): ")
    distance = float(input("Enter distance from previous point (in km): "))
    data.append([location, time, distance])
    total_distance += distance
    i += 1

print("\n-------------------- Delivery Summary --------------------")
print("Starting location:", data[0][0])
print("Ending location:", data[-1][0])
print("Total distance covered:", total_distance, "km")