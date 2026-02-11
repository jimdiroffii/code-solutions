#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS             0
#define FAILURE             1
#define ERR_ARGV_NULL       2
#define ERR_NEGATIVE        3
#define ERR_MISSING_ARG     4
#define ERR_NOT_A_NUMBER    5
#define ERR_OUT_OF_RANGE    6
#define ERR_STRING          7
#define ERR_TRAILING_CHARS  8
#define ERR_TOO_MANY_ARG    9
#define ERR_BUFF_OVERFLOW   10

#define MAX_DIGITS 1000000

void usageMsg(char *argv[]) {
  const char *program = "./program";

  if (argv != NULL && argv[0] != NULL) {
    program = argv[0];
  }

  fprintf(stderr, "Usage: %s <unsigned long integer>\n", program);
}

int validateInput(int argc, char* argv[], unsigned long *outValue) {
  if (argc < 2) return ERR_MISSING_ARG;
  if (argc > 2) return ERR_TOO_MANY_ARG;
  if (argv == NULL || argv[1] == NULL) return ERR_ARGV_NULL;

  const char *s = argv[1];
  while (isspace((unsigned char)*s)) {
    s++;
  }
  if (*s == '\0') return ERR_NOT_A_NUMBER;
  if (*s == '-') return ERR_NEGATIVE;

  char *endptr;
  errno = 0;

  unsigned long input = strtoul(s, &endptr, 10);

  if (s == endptr) return ERR_NOT_A_NUMBER;
  if (errno == ERANGE) return ERR_OUT_OF_RANGE;
  if (errno != 0) return ERR_STRING;
  if (*endptr != '\0') return ERR_TRAILING_CHARS;

  *outValue = input;
  return SUCCESS;
}

int factorialDigitSum(unsigned long n, unsigned long *result) {
  if (n == 0 || n == 1) {
    *result = 1;
    return 0;
  }

  int digits[MAX_DIGITS] = {0};

  int len = 1;
  digits[0] = 1;

  for (int i = 0; i < n; ++i) {
    int carry = 0;

    for (int j = 0; j < len; ++j) {
      int x = digits[j] * (i + 1) + carry;
      digits[j] = x % 10;
      carry = x / 10;
    }
    
    while (carry > 0) {
      if (len >= MAX_DIGITS) return ERR_BUFF_OVERFLOW;
      digits[len++] = carry % 10;
      carry /= 10;
    }
  }

  unsigned long sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += digits[i];
  }

  *result = sum;
  return 0;
}

int main(int argc, char *argv[]) {
  unsigned long n = 0;
  int status = validateInput(argc, argv, &n);
  
  if (status != SUCCESS) {
    switch (status) {
      case ERR_ARGV_NULL:
        fprintf(stderr, "Error: Unexpected argv NULL value\n");
        break;
      case ERR_NEGATIVE:
        fprintf(stderr, "Error: Input must not be negative\n");
        break;
      case ERR_MISSING_ARG:
        fprintf(stderr, "Error: Missing required argument\n");
        break;
      case ERR_TOO_MANY_ARG:
        fprintf(stderr, "Error: Too many arguments\n");
        break;
      case ERR_NOT_A_NUMBER:
        fprintf(stderr, "Error: No digits in input '%s'\n", argv[1]);
        break;
      case ERR_OUT_OF_RANGE:
        fprintf(stderr, "Error: Input out of range. Max: %lu\n", ULONG_MAX);
        break;
      case ERR_STRING:
        fprintf(stderr, "Error: %s\n", strerror(errno));
        break;
      case ERR_TRAILING_CHARS:
        fprintf(stderr, "Error: Extra chars beyond number detected\n");
        break;
      }
    usageMsg(argv);
    return status;
  }

  unsigned long result = 0;
  
  status = 0;
  status = factorialDigitSum(n, &result);

  if (status == ERR_BUFF_OVERFLOW) {
    fprintf(stderr, "Error: Buffer overflow, use a smaller value\n");
    return FAILURE;
  }

  printf("input:  %lu!\n", n);
  printf("result: %lu\n", result);

  return SUCCESS;
}