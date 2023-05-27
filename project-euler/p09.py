# A Pythagorean triplet is a set of three natural numbers, 
# 
# a < b < c, for which,
# a^2 + b^2 = c^2
#
# For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.
#
# triplets are all even numbers, or two odds and an even
#
# construct a triple when m and n are ints m > n
# a = m^2 - n^2
# b = 2mn
# c = m^2 + n^2
# Example: m=2 and n=1, (a=3,b=4,c=5)

import math

def main():
  n = 1000
  
  for b in range(n):
    for a in range(1, b):
        c = math.sqrt( a * a + b * b)
        if c % 1 == 0:
            if a + b + c == 1000:
                print(a, b, int(c))
                tmp = a * b * c
                print (tmp)

if __name__ == "__main__":
    main()