data=[]

n=0
while(n<=0):
    n=int(input("enter No. of employes : "))
    if(n<=0):
        print("invalid input, try again ")

i=1
while(i<=n):
    name=input(f"enter name of employee {i} : ")
    data.append([0,0,name,0])
    i+=1


i=1
while(i<=30):
    print("--------------------DAY ",i,"--------------------")
    for k in range(1,n+1):
        name=input(f"enter name of employee {k} : ")
        p=(input("present or absent (p/a)")).lower()

        for j in range(len(data)):
            if(name==data[j][2]):
                if(p=="p"):
                    data[j][0]+=1
                    data[j][3]=(data[j][0]/30)*100
                else:data[j][1]+=1
    
    i+=1


print("Overall details of the Employees are under")

for i in range(1, n + 1):

    print("\n--------------------Employee No. ",i,"--------------------")
    print("Name of the employee : ",data[i-1][2])
    print("Present count : ", data[i-1][0])
    print("Absent count : ", data[i-1][1])
    print("Attendance percentage : ", data[i-1][3])




data.sort(reverse=True)


if(data[0][0]==30):
    print("\nEmpolyee with perfect attandence is : ", data[0][2])
else:
    print("\nEmpolyee with highest attandence is : ", data[0][2]," with average of : ",data[0][3])

print("Employee with most absents : ", data[len(data)-1][2], " with average present is : ",data[len(data)-1][3])






