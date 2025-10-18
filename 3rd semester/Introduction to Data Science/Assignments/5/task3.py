l = "yes"
grade = []

while l == "yes":
    name = input("Name of the student: ")

    maths = int(input("Marks obtained in Maths: "))
    maths_total = int(input("Total marks in Maths: "))

    science = int(input("Marks obtained in Science: "))
    science_total = int(input("Total marks in Science: "))

    english = int(input("Marks obtained in English: "))
    english_total = int(input("Total marks in English: "))

    urdu = int(input("Marks obtained in Urdu: "))
    urdu_total = int(input("Total marks in Urdu: "))

    islamiyat = int(input("Marks obtained in Islamiyat: "))
    islamiyat_total = int(input("Total marks in Islamiyat: "))

    total_obtained = maths + science + english + urdu + islamiyat
    total_possible = maths_total + science_total + english_total + urdu_total + islamiyat_total

    average_percentage = (total_obtained / total_possible) * 100
    grade.append((average_percentage, name))

    if len(grade) >= 3:
        l = input("Do you want to add more students (yes/no): ")
        if l != "yes":
            break

for percentage, name in grade:
    print("Name of student =", name, "Average Percentage =", round(percentage, 2), "%")

grade.sort(reverse=True)


print("\nTop 3 Positions:")
print("1st position:", grade[0][1], "with Average Percentage =", round(grade[0][0], 2), "%")
print("2nd position:", grade[1][1], "with Average Percentage =", round(grade[1][0], 2), "%")
print("3rd position:", grade[2][1], "with Average Percentage =", round(grade[2][0], 2), "%")