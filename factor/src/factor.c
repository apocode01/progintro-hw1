#include <stdio.h>
#include <stdlib.h>  // For the atoll() function

/*
 - Filename: factor.c
 - Author: Apostolos Panousakis
 - Description: A program that factors semiprimes
*/

// Declare is_prime function
int is_prime(long long num);

int main(int argc, char* argv[]) {
  // Check if the user has provided 2 arguments (including program name)
  if (argc != 2) {
    printf("Usage: %s <semiprime>\n", argv[0]);
    return 1;
  }

  // Convert the argument to the long long variable type
  long long semiprime = atoll(argv[1]);

  // Check if 2 is a factor (only possible even number)
  if (semiprime % 2 == 0 && is_prime(semiprime / 2)) {
    printf("Factors: %d %lld\n", 2, semiprime / 2);
    return 0;
  }

  // Find the factors of the semiprime (except from 2)
  for (long long i = 3; i * i <= semiprime; i += 2) {
    if (is_prime(i) && semiprime % i == 0 && is_prime(semiprime / i)) {
      printf("Factors: %lld %lld\n", i, semiprime / i);
      return 0;
    }
  }

  // If no factors are found then the number is not a semiprime
  printf("Not a semiprime\n");
  return 1;
}

// The is_prime function returns 0 if a number is not prime and 1 if a number is
// prime
int is_prime(long long num) {
  if (num <= 1 || (num != 2 && num % 2 == 0)) {
    return 0;
  }
  // Number 2 is the only even prime number
  else if (num == 2) {
    return 1;
  }
  for (long long i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}