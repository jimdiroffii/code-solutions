# Find the sum of all the multiples of 3 or 5 below 1000.

def main():
    max = 1000
    sum = 0 
    i = 0
    while (i < max):
        if (i % 3 == 0):
            sum += i
        elif (i % 5 == 0):
            sum += i
        # print(sum)
        i += 1
    
    print(sum)

if __name__ == "__main__":
    main()