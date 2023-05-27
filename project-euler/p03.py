# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143?
#
# All integers are either prime, or can be made by multiplying 
# prime numbers together. 
#
# Find the first prime factor
# If the multiplier of the first prime factor is prime, done
# Else, find the next prime factor

from helpers import isPrime

def main():
    # num = 13195
    num = 600851475143
    # num = 6857
    # num = 654657

    for i in range(2, int (num / 2)):
        if (num % i) == 0:
            x = int (num / i)
            if isPrime(x) == True:
                print(x, "is the largest prime factor of", num)
                break

    else:
        print(num, "is a prime")

if __name__ == "__main__":
    main()