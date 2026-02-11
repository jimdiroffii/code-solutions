#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define SUCCESS             0
#define ERR_ARGV_NULL       2
#define ERR_NEGATIVE        3
#define ERR_MISSING_ARG     4
#define ERR_NOT_A_NUMBER    5
#define ERR_OUT_OF_RANGE    6
#define ERR_CONVERSION      7
#define ERR_TRAILING_CHARS  8
#define ERR_TOO_MANY_ARG    9

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
  if (errno != 0) return ERR_CONVERSION;
  if (*endptr != '\0') return ERR_TRAILING_CHARS;

  *outValue = input;
  return SUCCESS;
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
      case ERR_CONVERSION:
        fprintf(stderr, "Error: Input could not be converted to 'unsigned long integer'\n");
        break;
      case ERR_TRAILING_CHARS:
        fprintf(stderr, "Error: Extra chars beyond number detected\n");
        break;
      }
    usageMsg(argv);
    return status;
  }

  printf("input: %lu\n", n);
  return SUCCESS;
}