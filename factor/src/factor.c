#include <stdio.h>
#include <stdlib.h>  // For the atoll() function

/*
 - Filename: factor.c
 - Author: Apostolos Panousakis
 - Description: A program that factors semiprimes
*/

int main(int argc, char* argv[]) {
  // Check if the user has provided 2 arguments (including program name)
  if (argc != 2) {
    printf("Usage: %s <semiprime>\n", argv[0]);
    return 1;  // Unsuccessful termination with exit code 1
  }

  // Convert the argument to the long long variable type
  long long semiprime = atoll(argv[1]);

  // Check if the argument is a negative number
  if (semiprime < 0) {
    return 1;  // Unsuccessful termination with exit code 1
  }

  // Check if 2 is a factor (only possible even number)
  if (semiprime % 2 == 0) {
    printf("Factors: %d %lld\n", 2, semiprime / 2);
    return 0;  // Successful termination with exit code 0
  }

  // Find the factors of the semiprime (except from 2)
  for (long long i = 3; i * i <= semiprime; i += 2) {
    if (semiprime % i == 0) {
      printf("Factors: %lld %lld\n", i, semiprime / i);
      return 0;  // Successful termination with exit code 0
    }
  }

  return 1;  // Unsuccessful termination with exit code 1
}