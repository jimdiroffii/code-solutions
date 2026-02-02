#include <stdio.h>

int main() {
	long long a = 0, b = 1, sum = 0;
	const long long N = 4000000000000000000;
	while (b < N) {
		long long tmp = a + b;
		if (tmp % 2 == 0) sum += tmp;
		a = b;
		b = tmp;
	}

	printf("sum = %lld", sum);
	return 0;
}

