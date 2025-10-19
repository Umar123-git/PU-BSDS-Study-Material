data=[]
total_marks=int(input("inter total marks of the quiz : "))
minimun_marks=total_marks/2

students=int(input("enter total no. of students : "))

i=1
average_score=0
while(i<=students):
    print("--------------------", i ,"--------------------")
    name=input("enter name of the student")
    time=float(input("enter time taken to complete the quiz : "))
    score=int(input("enter obtained marks : "))
    data.append([score,time,name])

    average_score+=score
    i+=1

average_score=(average_score/(students*total_marks))*100

data.sort(reverse=True)

print("overall class average score is : ",average_score)
print("Student who scores highest is ",data[0][2], " With marks = ",data[0][0])

for i, (s,t,n) in enumerate(data):
    if(s<minimun_marks and i!=0):
        print("Student who passed the quiz with minimum marks is : ",data[i-1][2], " With marks = ",data[i-1][0] )
        break
