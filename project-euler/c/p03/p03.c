#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  FALSE = 0,
  TRUE = 1
} bool_t;

/***
 * Return an array of factors
 * Caller is responsible for freeing the returned array, if not NULL
 * If isPrimeCheck is TRUE, returns factors[0] == -1, if n is not prime
 * If isPrimeCheck is TRUE, returns factors[0] == 0, if n is prime
 * Otherwise, returns an array of factors (not necessarily prime)
 */
long long *factor(long long n, unsigned int size, bool_t isPrimeCheck)
{
  long long divisor = 2;
  long long quotient = n - 1;
  int counter = 0;
  long long *factors = (long long *)malloc(size * sizeof(long long));
  if (factors == NULL)
  {
    return NULL;
  }

  if (isPrimeCheck == TRUE)
  {
    factors[0] = 0; // Assume prime
  }

  while (divisor < quotient)
  {
    if (n % divisor == 0 && isPrimeCheck == TRUE)
    {
      factors[0] = -1; // Not prime
      break;
    }
    else if (n % divisor == 0)
    {
      quotient = n / divisor;
      factors[counter++] = divisor;
      factors[counter++] = quotient;
      divisor = n / quotient;
    }

    ++divisor;
  }

  return factors;
}

/* Pg. 87 - The C Programming Language (2nd Ed) - Recursive Quicksort */
/* qsort: sort v[left]..v[right into increasing order */
void _Qsort(long long v[], int left, int right)
{
  int i, last;
  void swap(long long v[], int i, int j);

  if (left >= right)                  /* do nothing if array contains */
    return;                           /* fewer than two elements */
  swap(v, left, (left + right) / 2);  /* move partition elem */
  last = left;                        /* to v[0] */
  for (i = left + 1; i <= right; i++) /* partition */
    if (v[i] > v[left])
      swap(v, ++last, i);
  swap(v, left, last); /* restore partition elem */
  _Qsort(v, left, last - 1);
  _Qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(long long v[], int i, int j)
{
  long long temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int main()
{
  const long long n = 600851475143;
  const unsigned int size = 14;
  int counter = 0;

  long long *factors = factor(n, size, FALSE);

  if (factors == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  if (factors[0] == 0)
  {
    printf("%lld is prime\n", n);
    free(factors);
    return 0;
  }

  _Qsort(factors, 0, size - 1);

  for (size_t i = 0; i < size; i++)
  {
    printf("factor[%d] = %lld\n", counter, factors[i]);
    counter++;
  }

  printf("Number of factors found: %d\n", counter);

  /***
   * Prime Factor Check
   */

  long long *primeFactors = NULL;
  for (size_t i = 0; i < size; i++)
  {
    free(primeFactors);
    primeFactors = factor(factors[i], size, TRUE);
    if (primeFactors == NULL)
    {
      printf("Memory allocation failed\n");
      free(factors);
      return 1;
    }

    if (primeFactors[0] == 0)
    {
      printf("%lld is prime\n", factors[i]);
      break;
    }
    else
    {
      printf("%lld is not prime\n", factors[i]);
    }
  }

  free(primeFactors);
  free(factors);
  return 0;
}