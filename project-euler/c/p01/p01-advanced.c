#include <stdio.h>

static long long sum_multiples(long long k, const long long N) {
	long long m = (N - 1) / k;
	return k * m * (m+1) / 2;
}

int main() {
	const long long N = 1000;
	long long sum = sum_multiples(3,  N)
								+ sum_multiples(5,  N)
								- sum_multiples(15, N);

	printf("sum = %lld\n", sum);
	return 0;
}
