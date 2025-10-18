

l="yes"

cart=[]

while(l=="yes"):
    check1=input("Do you wants to add some iteams (yes/no)")
    while(check1=="yes"):
        iteam_name=input("enter name of the iteam : " )
        price=int(input("enter price of the iteam : "))
        #l = (price,iteam_name)
        cart.append([price,iteam_name])
        check1=input("Do you wants to add some more iteams (yes/no)")

    check2=input("Do you wants to update or remove iteam from the cart or do nothing (update/remove/nothing)")
    if(check2=="update"):
        if(len(cart)==0):
            print("cart is empty first add the iteam ")
        else:
            while(check2=="update"):
                exchange=input("inter the name of the iteam to update : ")
                price=int(input("Also the price of the updated iteam : "))
                t=False
                for x, (p, name) in enumerate(cart):
                    if(name==exchange):
                        t=True
                        cart[x]=[price,exchange]
                        print("iteam is updated successfully")
                        break
                if(t==False):
                    print("invalid input, try again")
                    continue
                t=input("do you update more iteams (yes/no)")
                if(t=="no"): break

    if(check2=="remove"):
        if(len(cart)==0):
            print("cart is empty first add the iteam ")

        else:
             while(check2=="remove"):
                remove=input("inter the name of the iteam to remove : ")
                t=False
                for i, (p, name) in enumerate(cart):
                    if(name==remove):
                        t=True
                        cart.pop(i)
                        print("iteam is removed from the cart")
                        break
                if(t==False):
                    print("invalid input, try again")
                    continue
                t=input("do you remove more iteams (yes/no)")
                if(t=="no"): break
    
    l=input("Before making Total do you want any change in the cart (yes/no)")

cart.sort(reverse=True)
total=0
for price, name in cart:
    total+=price

if cart:
    print("Total price is : ", total)
    print("Most expensive item is:", cart[0][1])
else:
    print("Cart is empty.")



                    


        
