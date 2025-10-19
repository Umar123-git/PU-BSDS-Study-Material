
data=[]
avgtem=0
for i in range(30):
    print(f"\n--------------------DAY {i+1}--------------------")
    weather=input("weather condition sunny,rainy,cloudy,pleasant : ")
    temp = float(input("temperature in celcius : "))
    avgtem+=temp
    data.append([temp,weather,i])
avgtem/=30
data.sort(reverse=True)
print("Hottest day is ",data[0][2]," with temperature = ",data[0][0])
print("Average temperature of month= ",avgtem)

sunny=0
rainy=0
cloudy=0
pleasant=0

for i in range(30):
    if(data[i][1]=="sunny"):sunny+=1
    if(data[i][1]=="rainy"):rainy+=1
    if(data[i][1]=="cloudy"):cloudy+=1
    if(data[i][1]=="pleasent"):pleasant+=1


m=0
freq=""
if(m<sunny):
    m=sunny
    freq="sunny"

if(m<cloudy):
    m=cloudy
    freq="cloudy"

if(m<rainy):
    m=rainy
    freq="rainy"

if(m<pleasant):
    m=pleasant
    freq="pleasant"


print("Most frequent weather condition is ",freq)

