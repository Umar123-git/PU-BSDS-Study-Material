


traffic_logs = [
    "id:501,zone:A1,vehicle:Car,speed:62,time:08:30,violations:[None],status:Smooth",
    "id:502,zone:A1,vehicle:Bike,speed:85,time:09:10,violations:[Helmet],status:Busy",
    "id:503,zone:B2,vehicle:Bus,speed:45,time:17:25,violations:[None],status:Smooth",
    "id:504,zone:C3,vehicle:Car,speed:110,time:14:15,violations:[Overspeed],status:Congested",
    "id:505,zone:A1,vehicle:Truck,speed:40,time:18:50,violations:[None],status:Smooth"
]


print("-----------------question 1---------------------")

def parse_log(log):
    parts = log.split(",")
    data = {}

    for part in parts:
        key, value = part.split(":",1)

        if key == "id":
            data[key] = int(value)
        elif key == "speed":
            data[key] = int(value)
        elif key == "violations":
            # Remove brackets and split
            v = value.strip("[]")
            data[key] = [] if v == "None" else [v]
        else:
            data[key] = value


    return data


structured_logs=[]
for log in traffic_logs:
    structured_logs.append(parse_log(log))


for entry in structured_logs:
    print(entry)


# question 2
print("-----------------question 2---------------------")
data={}
for entry in structured_logs:
    zone = entry["zone"]
    speed = entry["speed"]

    if zone not in data:
        data[zone]=[]
    data[zone].append(speed)


avg={}
for zone, speed in data.items():
    avg[zone] = sum(speed)/len(speed)

for zone, avg in avg.items():
    print(f"Zone {zone}: Average Speed = {avg:.2f} km/h")



# question 3
print("-----------------question 3---------------------")
peek = {}

for v in structured_logs:
    hour = int(v["time"].split(":")[0])
    peek[hour] = peek.get(hour, 0) + 1  


peak_hour = max(peek, key=peek.get)
peak_count = peek[peak_hour]

print("Peak Hour:", peak_hour, "with", peak_count, "entries")




# question 4
print("-----------------question 4---------------------")
vehicle={}

for v in structured_logs:
    if v["speed"]>80:
        vehicle[v["id"]]=v

for v in vehicle.values():
    print(v["vehicle"],v["speed"])


# question 5
print("-----------------question 5---------------------")
data={}

for v in structured_logs:
    if v["violations"]!=[]:
        viol = str(v["violations"])
        viol = viol.strip("[]",).strip("'")
        data[viol] = data.get(viol,0)+1
    
for d in data.items():
    print(d)



# question 6
print("-----------------question 6---------------------")
data={}

car = 0
for v in structured_logs:
    if v["vehicle"]!="":
        car+=1
    zone = v["zone"]
    if zone not in data:
        data[zone]={"vehicles":0,"violation":0}
    data[zone]["vehicles"]+=1
    if v["violations"]: 
        data[zone]["violation"]+=1
      

for z,s in data.items():
    #print(veh["vehicles"],viol["violation"])
    veh = s["vehicles"]
    viol = s["violation"]
    index = (veh - viol)/veh
    print(f"Zone {z}: Violation Index = {index:.2f}")


# question 7
print("-----------------question 7---------------------")

data={}

for v in structured_logs:
    vehicle = v["vehicle"]
    speed = v["speed"]

    if vehicle != "":
        if vehicle not in data:
            data[vehicle]={"count":0, "avg speed":0, "violations":0}
        data[vehicle]["count"]+=1
        data[vehicle]["avg speed"]=(data[vehicle]["avg speed"]+speed)/data[vehicle]["count"]
        if v["violations"]:
            data[vehicle]["violations"]+=1
    

for d in data.items():
    print(d)

# question 8
print("-----------------question 8---------------------")

data={}
data["Congested"]=[]
for v in structured_logs:
    if v["status"]=="Congested":
        zone = v["zone"]
        data["Congested"].append(zone)

for p in data.items():
    print(p)


# question 9
print("-----------------question 10---------------------")

data = {}

for v in structured_logs:
    h = int(v["time"].split(":")[0])

    if 6<=h<12:
        data[v["id"]]="morning"
    elif 12<=h<18:
        data[v["id"]]="afternoon"
    elif 18<=h<22:
        data[v["id"]]="evening"
    else:
        data[v["id"]]="night"

for p,q in data.items():
    print(f"ID {p} -> {q}")



# question 10
print("-----------------question 10---------------------")

from collections import Counter

zone_report = {}

for v in structured_logs:
    zone = v["zone"]
    vehicle = v["vehicle"]
    speed = v["speed"]
    violations = len(v["violations"])
    
    if zone not in zone_report:
        zone_report[zone] = {"vehicles": 0,"avg speed": 0,"violations": 0,"vehicle_types": []}
    
    zone_report[zone]["vehicles"] += 1
    zone_report[zone]["avg speed"] = (zone_report[zone]["avg speed"]+speed)/zone_report[zone]["vehicles"]
    zone_report[zone]["violations"] += violations
    zone_report[zone]["vehicle_types"].append(vehicle)


for zone, stats in zone_report.items():
    avg_speed = stats["avg speed"]
    common_vehicle = Counter(stats["vehicle_types"]).most_common(1)[0][0]
    safety_index = (stats["vehicles"] - stats["violations"]) / stats["vehicles"]
    
    if safety_index >= 0.8:
        safety_category = "Safe"
    elif safety_index >= 0.5:
        safety_category = "Moderate"
    else:
        safety_category = "Unsafe"
    
    print(f"Zone {zone}: Vehicles={stats['vehicles']}, "f"Avg Speed={avg_speed:.2f}, Violations={stats['violations']}, "f"Common Vehicle={common_vehicle}, Safety={safety_category}")