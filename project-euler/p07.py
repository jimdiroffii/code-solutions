# By listing the first six prime numbers: 
# 2, 3, 5, 7, 11, and 13, 
# we can see that the 6th prime is 13.

# What is the 10001st prime number?

from helpers import isPrime
# from helpers import PrimeofEratosthenes

def main():
    max = 10001
    n = 2
    counter = 0

    while counter < max:
        if isPrime(n) == True:
        # if PrimeofEratosthenes(n) == True:
            counter += 1
        n += 1

    print(n - 1, "is prime #", end="")
    print(max)

if __name__ == "__main__":
    main()