import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

w = int(input())
h = int(input())

map = []
key = []

for i in range(h):
    line = input()
    line = line.split()
    print(line, file=sys.stderr, flush=True)
            
    for i in line:
        i.split()
        map.append(i)
        keyLine = []
        for i in range(w):
            keyLine.append(0)
        key.append(keyLine)

#print(map, file=sys.stderr, flush=True)
#print(key, file=sys.stderr, flush=True)

for i in range(h):
    for j in range(w):
        #print(map[i][j], file=sys.stderr, flush=True)

        if map[i][j] == "x":

            # Debug
            #print("found x", file=sys.stderr, flush=True)
            #print("i=", i, " j=", j, " key[i][j]=", key[i][j], file=sys.stderr, flush=True)
            
            # We found a mine, so we set the value to -100, which will ensure that 
            # this value stays below zero when reprinting the key. 
            key[i][j] -= 100
            
            #print("i=", i, " j=", j, " key[i][j]=", key[i][j], file=sys.stderr, flush=True)

            # We found an x, now we need to increment the surrounding boxes
            # The boxes are currently 0. We need to ensure we properly care 
            # for the boundries of the array. 
            #
            # I want to use the array slicing system I seen in Arlette's class. 
            # By using [-1:0] and so on, we can designate each of the surrounding
            # array blocks. 
            
            # Increment Blocks - Working for one mine
            # key[i + 1][j + 1] += 1
            # key[i + 1][j] += 1
            # key[i + 1][j - 1] += 1

            # key[i - 1][j + 1] += 1
            # key[i - 1][j] += 1
            # key[i - 1][j - 1] += 1
            
            # key[i][j + 1] += 1
            # key[i][j - 1] += 1

            # Increment with conditions for edge checking
            # We have four edges to check
            # i - 1, i + 1, j - 1 and j + 1
            # We could also be in one of the four corners,
            # which is touching two edges. 
            # We should perform edge checks, creating booleans
            # and drop the necessary equations in. 
            # w, j = width, columns
            # h, i = height, rows
            left = False
            right = False
            top = False
            bottom = False

            if i - 1 < 0:
                top = True
            if i + 1 >= h:
                bottom = True
            if j - 1 < 0:
                left = True
            if j + 1 >= w:
                right = True

            # Top left corner
            if top == True and left == True:
                key[i][j + 1] += 1 # middle right
                key[i + 1][j] += 1 # bottom middle
                key[i + 1][j + 1] += 1 # bottom right

            # Top right corner
            elif top == True and right == True:
                key[i][j - 1] += 1 # middle left
                key[i + 1][j - 1] += 1 # bottom left
                key[i + 1][j] += 1 # bottom middle
            
            # Bottom left corner
            elif bottom == True and left == True:
                key[i - 1][j] += 1 # top middle
                key[i - 1][j + 1] += 1 # top right
                key[i][j + 1] += 1 # middle right

            # Bottom right corner
            elif bottom == True and right == True:
                key[i - 1][j - 1] += 1 # top left
                key[i - 1][j] += 1 # top middle
                key[i][j - 1] += 1 # middle left

            # Top
            elif top == True:
                key[i][j - 1] += 1 # middle left
                key[i][j + 1] += 1 # middle right
                key[i + 1][j - 1] += 1 # bottom left
                key[i + 1][j] += 1 # bottom middle
                key[i + 1][j + 1] += 1 # bottom right

            # Bottom
            elif bottom == True:
                key[i - 1][j - 1] += 1 # top left
                key[i - 1][j] += 1 # top middle
                key[i - 1][j + 1] += 1 # top right
                key[i][j - 1] += 1 # middle left
                key[i][j + 1] += 1 # middle right

            # Left
            elif left == True:
                key[i - 1][j] += 1 # top middle
                key[i - 1][j + 1] += 1 # top right
                key[i][j + 1] += 1 # middle right
                key[i + 1][j] += 1 # bottom middle
                key[i + 1][j + 1] += 1 # bottom right

            # Right
            elif right == True:
                key[i - 1][j - 1] += 1 # top left
                key[i - 1][j] += 1 # top middle
                key[i][j - 1] += 1 # middle left
                key[i + 1][j - 1] += 1 # bottom left
                key[i + 1][j] += 1 # bottom middle
            
            else:
                key[i - 1][j - 1] += 1 # top left
                key[i - 1][j] += 1 # top middle
                key[i - 1][j + 1] += 1 # top right
                key[i][j - 1] += 1 # middle left
                key[i][j + 1] += 1 # middle right
                key[i + 1][j - 1] += 1 # bottom left
                key[i + 1][j] += 1 # bottom middle
                key[i + 1][j + 1] += 1 # bottom right

# Rewrite the key
for i in range(h):
    for j in range(w):
        if key[i][j] <= 0:
            key[i][j] = "."            

for i in range(h):
    for j in range(w):
        print(key[i][j], end="")
    print()