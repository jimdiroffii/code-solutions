# Helpers for the Project Euler problems

# Return True or False based on if input is a prime number
# The num / 2 cuts runtime in half, but takes a really 
# long time on any large numbers. Otherwise works perfectly. 
def isPrime(n):

    if n == 2 or n == 3:
        return True
    
    if n < 5:
        return False
    
    for i in range(2, (int (n / 2) + 1)):
        if (n % i) == 0:
            return False
    else:
        return True

# The Sieve Of Eratosthenes
# A faster method of finding any 
# prime number equal or less than N
# in O(N log (log N)) time, used for 
# N < 10M or so
# Returns array of primes

def SieveOfEratosthenes(n):
    # Create array of all numbers from 0..num
    prime = [True for i in range(n + 1)]
    p = 2
    # for every number in the array, starting 
    # at 2 * 2 = 4
    while (p * p <= n):
        # If prime is True, the number must be prime
        if (prime[p] == True):
            # Update all multiples of prime number to False
            for i in range(p * p, n + 1, p):
                prime[i] = False
        # Go to next number in array
        p += 1

    return prime

# Use Sieve of Eratosthenes to determine if input 
# is a prime number. Return True or False
# Works for small N, but gets exponentially slower 
# as N grows. It is checking and rechecking the same 
# array of primes over and over again. I think using a 
# method like this could work, but I only need to create the 
# prime array once. 

def PrimeofEratosthenes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    
    if prime[n]:
        return True
    else:
        return False

# Factorization
# Return all the factors of a given input number
def factors(n):
    return