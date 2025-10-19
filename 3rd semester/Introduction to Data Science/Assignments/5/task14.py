capacity = int(input("enter total room capacity of the hotel :"))
standard = int(capacity*0.5)
executive= int(capacity*0.3)
premium  = int(capacity*0.2)

price_standard = 20
price_executive = 50
price_premium = 100

data=[]

t="yes"
while(t=="yes"):

    print("available rooms with price for different catagories are ")
    print("Number of Standard rooms : ", standard ,"Rent per night : ", price_standard,"$")
    print("Number of Executive rooms : ", executive,"Rent per night : ", price_executive,"$")
    print("Number of Premium rooms : " ,  premium ,"Rent per night : ", price_premium,"$")

    t=input("Do you wants to book a room (yes/no)")
    if(t!="yes"): break
    name=input("Enter your name :")

    r=int(input("In which catagories do you want to book the room type 1, 2, or 3 for Standard, Exective or Premium respectfully : "))
    if(r<1 or r>3):
        print("Invalid input, try again")
        continue
    if(r==1 or r==2 or r==3):
        if(r==1):
            if standard==0 :
                print("Sorry rooms are already booked")
                continue
        if(r==2):
            if executive==0:
                print("Sorry rooms are already booked")
                continue
        if(r==3):
            if premium==0:
                print("Sorry rooms are already booked")
                continue
    days=int(input("How many days to book the room : "))

    if(r==1):
        total=price_standard*days
        standard-=1
    if(r==2):
        total=price_executive*days
        executive-=1
    if(r==3):
        total=price_premium*days
        premium-=1
    data.append([name,r,days,total])


while data:
    checkout = input("\nEnter the name of the person to check out: ")
    found = False
    for i, (person, rom, d, t) in enumerate(data):
        if person == checkout:
            found = True
            if rom == 1:
                print("You booked a Standard room.")
                standard += 1
            elif rom == 2:
                print("You booked an Executive room.")
                executive += 1
            elif rom == 3:
                print("You booked a Premium room.")
                premium += 1

            print("Number of days booked:", d)
            print("Your grand total is:", t,"$")
            data.pop(i)
            break
    if not found:
        print("No booking found under that name.")


            





    
