import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

closest = sys.maxsize

n = int(input())  # the number of temperatures to analyse

if n == 0:
    print("0")

for i in input().split():
    # t: a temperature expressed as an integer ranging from -273 to 5526
    t = int(i)

    if t == 0:
        closest = t
    elif t > 0:
        print("POS> t: ", t, " closest: ", closest, file=sys.stderr, flush=True)
        if t <= abs(closest):
            closest = t
    elif t < 0:
        t2 = abs(t)
        print("NEG> t: ", t, " t2: ", t2, " closest: ", closest, file=sys.stderr, flush=True)
        if t2 < abs(closest):
            closest = t

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
if n != 0:
    print(closest)
