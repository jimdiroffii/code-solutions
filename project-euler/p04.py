# A palindromic number reads the same both ways. 
# The largest palindrome made from the product of 
# two 2-digit numbers is 9009 = 91 × 99.

# Find the largest palindrome made from the product 
# of two 3-digit numbers.
#
# The largest 3 digit number is 999. Start there. 
# To read a palindromic number, we need to read the 
# number string forwards and backwards and see if they match. 
# We also need to decrement x and y logically for every
# non match. 990 * 999 may make a number, but 998 * 998 is a 
# bigger number. 
# Need to calculate the sum, and only reduce y when the product of
# the next xy calculation will be less than if we reduced y. 
# First take 999 * 999 = 998,001.
#            998 * 999 = 997,002.
#            997 * 999 = 996,003.
#            998 * 998 = 996,004.
# Reduce x until we find a palindrome. 
# Then reduce y by one
# Iterate through x trying to find a palindrome larger than the previous.
# We won't have to go past the previous iteration


def main():
    x = 9999
    y = 9999
    i = y
    highestpalindromicnumber = 0

    while x >= 100:
        while i >= 100:
            sum = x * i
            stringSum = str(sum)
            reversedSum = stringSum[::-1]
            if (stringSum == reversedSum):
                if highestpalindromicnumber < sum:
                    highestpalindromicnumber = sum
            i -= 1
        x -= 1
        i = y

    print(highestpalindromicnumber, "is the highest palindromic number")

if __name__ == "__main__":
    main()