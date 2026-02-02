#include <stdio.h>

int main() {
	const int max = 1000;
	const int a = 3, b = 5;
	long long sum = 0;

	for (int i = a; i < max; ++i) {
		if (i % a == 0 || i % b == 0) sum += i;
	}

	printf("sum = %lld\n", sum);
	return 0;
}
