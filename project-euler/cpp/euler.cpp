#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <vector>
#include <thread>
#include <atomic>
#include <fstream>

long getNumDivisors(long n)
{
    if (n == 1)
        return 1;
    long countDiv{2}; // every n > 1 is divisible by 1 and itself
    long sqrtN = std::sqrt(n);
    for (long i{2}; i <= sqrtN; i++)
    {
        if (n % i == 0)
            countDiv += 2;
        if (i * i == n)
            countDiv--;
    }
    return countDiv;
}

/* returns empty vector on failure */
std::vector<std::string> readFileToVector(std::string fName)
{
    std::ifstream fs{};
    fs.open(fName);
    if (!fs)
    {
        std::cout << "File error.\n";
        return {};
    }

    std::string line{};
    std::vector<std::string> vNums{};

    while (std::getline(fs, line))
    {
        if (line.empty())
        {
            continue;
        }

        vNums.push_back(line);
    }

    if (vNums.empty())
    {
        std::cout << "Read error.\n";
        return {};
    }

    return vNums;
}

void euler12()
{
    // Highly Divisible Triangle Number
    // Triangular numbers are formed by adding together the natural numbers
    // 1: 1
    // 3: 1+2
    // 28: 1+2+3+4+5+6+7
    // 28 is the first triangle number to have over 5 divisors.
    // 28: 1, 2, 4, 7, 14, 28
    // What is the first triangle number to have over 500 divisors?

    long triNum{};
    long numDivisors{};
    long i{};

    while (numDivisors <= 500)
    {
        triNum += ++i; // make next triangle number
        numDivisors = getNumDivisors(triNum);
    }

    std::cout << triNum << ": " << numDivisors << "\n";
}

void euler13()
{
    // Large sum
    // Work out the first ten digits of the following one-hundred 50-digit numbers
    // *numbers in euler13.txt
    std::vector<std::string> vNums = readFileToVector("euler13b.txt");
    long long sum{};
    std::string finalSum{};

    while (!vNums.empty())
    {
        for (auto it = vNums.begin(); it != vNums.end();) // grabs a string from the vector
        {
            if (it->empty())
            { // when we are done, all strings will be empty, and every vector element is erased
                it = vNums.erase(it);
                continue;
            }

            int n{};
            n = std::stoi(std::string(1, it->back())); // grab the last char as int
            sum += n;

            it->pop_back(); // remove the last char from the current string
            it++;           // goto next string
        }

        if (vNums.empty()) {
            break;
        }

        // we have the sum of a column
        // we need to store a single digit a the beginning of our output string
        // we need to keep the carry over sum for the next iteration
        if (sum < 10)
        {
            finalSum.insert(0, std::to_string(sum)); // store the last digit of sum into our final string
            sum = 0;
        }
        else
        {
            int m = sum % 10;                      // get last digit of sum
            finalSum.insert(0, std::to_string(m)); // store the last digit of sum into our final string
            sum /= 10;                             // remove last digit from sum
            sum = sum + (10 - (sum % 10));         // Bug, this always equals 10
        }
    }

    if (sum >= 10) {
        finalSum.insert(0, std::to_string(sum / 10));
    }
    std::cout << "sum: " << finalSum << "\n";
}

int main()
{
    clock_t startCPU = clock();                                 // cputime
    auto startReal = std::chrono::high_resolution_clock::now(); // realtime

    /*{ // Euler 12
        euler12();
    }*/
    { // Euler 13
        euler13();
    }

    clock_t endCPU = clock();
    double cpu_time_used = ((double)(endCPU - startCPU)) / CLOCKS_PER_SEC;
    std::cout << "CPU time: " << std::fixed << std::setprecision(6) << cpu_time_used << " seconds" << std::endl;

    auto endReal = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endReal - startReal;
    std::cout << "Real Time: " << std::fixed << std::setprecision(6) << duration.count() << " seconds" << std::endl;
}