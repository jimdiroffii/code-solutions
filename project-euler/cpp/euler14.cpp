#include <iostream>

int main()
{
    long startingNum = 0;
    long endingNum = 1000000;
    long n = startingNum;
    
    int max = 0;
    int maxValue = 0;
    int counter = 1;
    
    while (startingNum < endingNum) {
        ++startingNum;
        n = startingNum;
        
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            }
            else {
                n = 3 * n + 1;
            }
            
            ++counter;
            
            if (counter > max) {
                maxValue = startingNum;
                max = counter;
            }
        }
        
        counter = 1;
    }
    
    std::cout << "Max Sequence: " << max << std::endl;
    std::cout << "Max Value: " << maxValue << std::endl;
    
    return 0;
}
