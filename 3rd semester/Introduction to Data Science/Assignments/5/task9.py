teams = {}
matches = []
total_score = 0
match_count = 0

n = 0
while n <= 0:
    n = int(input("Enter number of teams: "))
    if n <= 0:
        print("Invalid input, try again.")

i = 1
while i <= n:
    name = input(f"Enter name of team {i}: ")
    teams[name] = 0
    i += 1

m = 0
while m <= 0:
    m = int(input("Enter number of matches played: "))
    if m <= 0:
        print("Invalid input, try again.")

i = 1
while i <= m:
    print(f"\n-------------------- Match {i} --------------------")
    team1 = input("Enter name of Team 1: ")
    score1 = int(input("Enter score of Team 1: "))
    team2 = input("Enter name of Team 2: ")
    score2 = int(input("Enter score of Team 2: "))
    matches.append([team1, score1, team2, score2])
    total_score += score1 + score2
    match_count += 1

    if score1 > score2:
        teams[team1] += 1
    elif score2 > score1:
        teams[team2] += 1

    i += 1

winner = max(teams, key=teams.get)
average_score = total_score / (match_count * 2)
participants = set()

for match in matches:
    participants.add(match[0])
    participants.add(match[2])

print("\n-------------------- Tournament Summary --------------------")
print("Winning team:", winner)
print("Average score per team per match:", round(average_score, 2))
print("Unique participating teams:", list(participants))