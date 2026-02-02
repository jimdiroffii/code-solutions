# 2520 is the smallest number that can be 
# divided by each of the numbers from 1 to 10 
# without any remainder.

# What is the smallest positive number that is 
# evenly divisible by all of the numbers from 1 to 20?
# 
# My starting point for the quotients is 2y since 
# the smallest number we are looking for, must be 
# at least 2y. 
#
# Start with our range, from x to y (1 to 10)
# Start with a number (quotient) that is twice as big as y

def main():
    x = 1
    y = 20
    num = y * 2
    i = x

    while i <= y:
        if (num % i) == 0:
            i += 1
        else:
            i = x
            num += 1

    print(num)
        
if __name__ == "__main__":
    main()