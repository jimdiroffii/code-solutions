#include <stdio.h>

int main() {
  int n = 10;
  int result = n;

  for (int i = n - 1; i > 0; --i) {
    result *= i;
  }

  printf("Result: %i", result);
  return 0;
}