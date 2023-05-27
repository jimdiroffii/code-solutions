# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.

# Python program to print all primes smaller than or equal to 
# n using Sieve of Eratosthenes 

from helpers import SieveOfEratosthenes
  
# driver program 
if __name__=='__main__': 
    n = 2000000
    print ("Following is the sum of all prime")
    print ("numbers less than or equal to", n)
    prime = SieveOfEratosthenes(n)
    
    sum = 0
    for p in range(2, n):
        if prime[p]: # is true
            sum += p

    print(sum)