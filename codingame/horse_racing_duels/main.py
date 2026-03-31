import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())

horses = []

for i in range(n):
    pi = int(input())
    horses.append(pi)

horses.sort()

answer = sys.maxsize

for i in range(n - 1):
    if horses[i + 1] - horses[i] < answer:
        answer = horses[i + 1] - horses[i]

# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(answer)
