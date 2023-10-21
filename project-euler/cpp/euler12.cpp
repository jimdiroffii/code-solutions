#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <chrono>
#include <ctime>
#include <vector>
#include <thread>
#include <atomic>

std::atomic<long> result(0);
std::atomic<bool> found(false);

long getNumDivisors(long n) {
    if (n == 1) return 1;
    long countDiv{2}; // every n > 1 is divisible by 1 and itself
    long sqrtN = std::sqrt(n);
    for (long i{2}; i <= sqrtN; i++) {
        if (n % i == 0) countDiv += 2;
        if (i * i == n) countDiv--;
    }
    return countDiv;
}

void euler12() {
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

    while (numDivisors <= 100) {
        triNum += ++i; // make next triangle number
        numDivisors = getNumDivisors(triNum);
    }

    std::cout << triNum << ": " << numDivisors << "\n";
}

long getTriangularDivisors(long n) {
    if (n % 2 == 0) {
        return getNumDivisors(n/2) * getNumDivisors(n+1);
    } else {
        return getNumDivisors(n) * getNumDivisors((n+1)/2);
    }
}

void euler12_threaded(long start, long end) {
    for (long i = start; i < end && !found; i++) {
        long triNum = i * (i + 1) / 2;
        if (getTriangularDivisors(i) > 500) {
            if (!found) {
                found = true;
                result = triNum;
            }
            return;
        }
    }
}

int main() {
    { // Euler 12
        clock_t startCPU = clock(); // cputime
        auto startReal = std::chrono::high_resolution_clock::now(); // realtime

        euler12();

        clock_t endCPU = clock();
        double cpu_time_used = ((double) (endCPU - startCPU)) / CLOCKS_PER_SEC;
        std::cout << "CPU time: " << std::fixed << std::setprecision(6) << cpu_time_used << " seconds" << std::endl;

        auto endReal = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endReal - startReal;
        std::cout << "Real Time: " << std::fixed << std::setprecision(6) << duration.count() << " seconds" << std::endl;
    }

    /*
    {
        auto startReal = std::chrono::high_resolution_clock::now();
        clock_t startCPU = clock();

        std::vector<std::thread> threads;
        long range = 10000;  // Adjust this based on expected solution range and number of threads
        int num_threads = std::thread::hardware_concurrency();  // Get number of supported concurrent threads

        for (int i = 0; i < num_threads; i++) {
            threads.push_back(std::thread(euler12_threaded, i * range, (i+1) * range));
        }
        
        for (auto &t : threads) {
            t.join();
        }

        clock_t endCPU = clock();
        double cpu_time_used = ((double) (endCPU - startCPU)) / CLOCKS_PER_SEC;
        std::cout << "CPU time: " << std::fixed << std::setprecision(6) << cpu_time_used << " seconds" << std::endl;

        auto endReal = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endReal - startReal;
        std::cout << "Real Time: " << std::fixed << std::setprecision(6) << duration.count() << " seconds" << std::endl;

        std::cout << "Result: " << result << std::endl;
    }
    */
}