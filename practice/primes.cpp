/* Find the first 25 prime numbers */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>

constexpr int kNumIter = 10000;

std::vector<int> sieveOfEratosthenes(int limit)
{
	std::vector<bool> isPrime(limit + 1, true);
	std::vector<int> primes;

	isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

	for (int i = 2; i * i <= limit; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= limit; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	// Collecting all prime numbers
	for (int i = 2; i <= limit; ++i)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}

	return primes;
}

void runEra()
{
	int limit = 104730; // Find primes up to this limit
	std::vector<int> primes = sieveOfEratosthenes(limit);

	// std::cout << "Prime numbers up to " << limit << " are:\n";
	// for (int prime : primes)
	// {
	// 	std::cout << prime << " ";
	// }
	// std::cout << std::endl;
}

void sieveOfJim()
{
	// Prime numbers are natural numbers greater than 1 that are divisible only by 1 and itself
	// The first prime numbers are: 2, 3, 5, 7, 11, 13, 17
	// It is guaranteed that all primes >2 will be odd numbers
	// Guaranteed n + 2 minimum for each sequential prime

	int n{2};

	// Keep track of the number of primes generated

	int counter{};

	// Find our first prime
	// We are starting at 2, and 2 is prime. Therefore, it can only be divisible by 1 and itself
	// Every number is divisible by 1 and itself, so no need to check those.
	// The largest divisor we need to check for will be <= to the square root of the number
	// i.e. sqrt(25) == 5, 5 is the largest divisor we care about.
	// i.e. sqrt(100) == 10, divisors 50, 25 and 20 don't matter, since they will be caught at 2, 4, and 5.
	// We check for even divisors by taking the modulo
	// Due to the special case of 2 being even, and sqrt(3) < 2, we will have special cases for those
	// The special case just helps avoid having a separate print statement for 2 and 3

	// First, wrap our counter
	while (counter < kNumIter)
	{
		// Our method will find anything that isn't a prime, so we assume a prime to start
		bool isPrime{true};

		// Run a prime check on each n
		// n is starting at 2, which is prime.
		// we don't care about 1, and we don't care about itself
		// the sqrt of 2 and 3 is < 2, so we can't start with 2 or 3
		// we can also catch early isPrime, which will immediately eliminate most numbers
		for (int i{2}; i <= std::sqrt(n) && n != 2 && n != 3 && isPrime; i += (i == 2) ? 1 : 2)
		{
			// divisor check
			if (n % i == 0)
			{
				isPrime = false;
			}
		}

		// did we catch a prime?
		if (isPrime)
		{
			// std::cout << n << " ";
			++counter;
		}

		// increase n by 2 if n isn't equal to 2
		n += (n == 2) ? 1 : 2;
	}

	// std::cout << "\n";
}

int main()
{
	auto startJim = std::chrono::high_resolution_clock::now(); // realtime

	sieveOfJim();

	auto endJim = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> durationJim = endJim - startJim;
	std::cout << "Jim Time: " << std::fixed << std::setprecision(6) << durationJim.count() << " seconds" << std::endl;

	auto startEra = std::chrono::high_resolution_clock::now(); // realtime

	runEra();

	auto endEra = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> durationEra = endEra - startEra;
	std::cout << "Era Time: " << std::fixed << std::setprecision(6) << durationEra.count() << " seconds" << std::endl;

	// double ratio = durationEra.count() / durationJim.count() * 100;
	double ratio = durationJim.count() / durationEra.count();
	std::cout << ratio << std::endl;
	std::cin.get();
}
