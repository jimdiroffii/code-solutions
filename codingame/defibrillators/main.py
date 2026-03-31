import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

lon = input()
lat = input()
n = int(input())

distance = sys.maxsize
answer = ""

print("DEBUG msg 1: lon=" + lon + " lat=" + lat, file=sys.stderr, flush=True)

for i in range(n):
    defib = input()
    print("DEBUG msg 2: defib=" + defib, file=sys.stderr, flush=True)

    location = defib.split(";")
    print("location[4]=" + str(location[4]), file=sys.stderr, flush=True) # long
    print("location[5]=" + str(location[5]), file=sys.stderr, flush=True) # lat

    lon1 = lon.split(",")
    lat1 = lat.split(",")
    lon2 = location[4].split(",")
    lat2 = location[5].split(",")

    lon1 = lon1[0] + "." + lon1[1]
    print("lon1=" + str(lon1), file=sys.stderr, flush=True)
    lat1 = lat1[0] + "." + lat1[1]
    print("lat1=" + str(lat1), file=sys.stderr, flush=True)
    lon2 = lon2[0] + "." + lon2[1]
    print("lon2=" + str(lon2), file=sys.stderr, flush=True)
    lat2 = lat2[0] + "." + lat2[1]
    print("lat2=" + str(lat2), file=sys.stderr, flush=True)

    x = (float(lon2) - float(lon1)) * math.cos((float(lat1) + float(lat2)) / 2)
    print("x=" + str(x), file=sys.stderr, flush=True)
    y = float(lat2) - float(lat1)
    print("y=" + str(y), file=sys.stderr, flush=True)
    d = math.sqrt((x*x)+(y*y)) * 6371
    print("d=" + str(d), file=sys.stderr, flush=True)

    if d < distance:
        distance = d
        answer = location[1]

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(answer)
