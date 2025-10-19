data = []
total_time = 0
total_stops = 0

n = 0
while n <= 0:
    n = int(input("Enter number of stops: "))
    if n <= 0:
        print("Invalid input, try again.")


for i in range(1, n + 1):
    print(f"\n-------------------- Stop {i} --------------------")
    name = input("Enter stop name: ")
    time = float(input("Enter time taken to reach this stop (in minutes): "))
    distance = float(input("Enter distance from start (in km): "))
    data.append([name, time, distance])
    total_time += time
    total_stops += 1


fastest_time = None
fastest_segment = ""

for i in range(1, len(data)):
    segment_time = data[i][1] - data[i - 1][1]
    if fastest_time is None or segment_time < fastest_time:
        fastest_time = segment_time
        fastest_segment = f"{data[i - 1][0]} → {data[i][0]}"


print("\n-------------------- Route Summary --------------------")
print("Total number of stops:", total_stops)
print("Total route time:", total_time, "minutes")
print("Fastest segment:", fastest_segment, "with time =", round(fastest_time, 2), "minutes")