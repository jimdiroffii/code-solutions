#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline uint64_t now_ns(void) {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t)ts.tv_sec * 1000000000ull + (uint64_t)ts.tv_nsec;
}

/* Your O(N) loop version */
static long long sum_loop(int N) {
	int a = 3, b = 5;
	long long sum = 0;
	for (int i = 3; i < N; ++i) {
		if (i % a == 0 || i % b == 0) sum += i;
	}
	return sum;
}

/* O(1) formula version */
static long long sum_multiples(long long k, long long N) {
	long long m = (N - 1) / k;
	return k * m * (m + 1) / 2;
}
static long long sum_formula(int N) {
	long long NN = (long long)N;
	return sum_multiples(3, NN) + sum_multiples(5, NN) - sum_multiples(15, NN);
}

static void bench(const char *name, long long (*fn)(int), int N, long long reps) {
	volatile long long sink = 0;  // stops "optimize everything away"
	uint64_t t0 = now_ns();
	for (long long i = 0; i < reps; ++i) {
		// keep N varying slightly so compiler can't constant-fold everything
		sink += fn(N + (int)(i & 1));
	}
	uint64_t t1 = now_ns();
	double total_ns = (double)(t1 - t0);
	printf("%-12s: total %.0f ns, %.2f ns/call, sink=%lld\n",
		name, total_ns, total_ns / (double)reps, sink);
}

int main(int argc, char **argv) {
	int N = (argc > 1) ? atoi(argv[1]) : 1000;
	long long reps = (argc > 2) ? atoll(argv[2]) : 20000000LL;

	// Warm up (helps with cache/branch predictor steady state)
	bench("warmup", sum_loop, N, 10000);

	bench("loop",    sum_loop,    N, reps);
	bench("formula", sum_formula, N, reps);
	return 0;
}

