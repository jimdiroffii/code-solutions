import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# ---
# Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.

# light_x: the X position of the light of power
# light_y: the Y position of the light of power
# initial_tx: Thor's starting X position
# initial_ty: Thor's starting Y position
light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

thor_tx, thor_ty = 0, 0

thor_tx = initial_tx
thor_ty = initial_ty

linedup_x = False
linedup_y = False

# game loop
while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # A single line providing the move to be made: N NE E SE S SW W or NW
    if thor_tx == light_x:
        linedup_x = True
    
    if thor_ty == light_y:
        linedup_y = True

    pos_y = 0
    if linedup_y != True:
        pos_y = light_y - thor_ty

    if pos_y > 0:
        print("S", end="")
        thor_ty = thor_ty + 1
    elif pos_y < 0:
        print("N", end="")
        thor_ty = thor_ty - 1

    pos_x = 0
    if linedup_x != True:
        pos_x = light_x - thor_tx

    if pos_x > 0:
        print("E", end="")
        thor_tx = thor_tx + 1
    elif pos_x < 0:
        print("W", end="")
        thor_tx = thor_tx - 1

    print("")

