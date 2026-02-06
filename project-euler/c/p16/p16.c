#include <stdio.h>

#define MAX_DIGITS 400 // 2^1000 has 302 digits, so 400 is plenty.

int main(void)
{
  int digits[MAX_DIGITS] = {0}; // digits[0] is least-significant digit
  int len = 1;                  // current number of digits in use

  digits[0] = 1; // start with 1, then multiply by 2 a thousand times

  for (int exp = 0; exp < 1000; exp++)
  {
    int carry = 0;
    for (int i = 0; i < len; i++)
    {
      int x = digits[i] * 2 + carry;
      digits[i] = x % 10;
      carry = x / 10;
    }
    while (carry > 0)
    {
      digits[len++] = carry % 10;
      carry /= 10;
    }
  }

  long sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum += digits[i];
  }

  printf("%ld\n", sum);
  return 0;
}
