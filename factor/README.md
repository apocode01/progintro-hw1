## Semiprime Factoring

A natural number is called a semiprime number when it is the product of exactly two prime numbers.

The purpose of this program is to factor semiprime numbers.

## Build & Dependencies

In order to run the project, you need the following tools:
1) `gcc`
2) `libgcc-multilib` (for 32-bit systems)

To install them on a Ubuntu system run the following command:

```sh 
apt-get install gcc gcc-multilib 
```

In order to compile the program run the following command:

```sh 
gcc -O3 -Wall -Wextra -Werror -o factor factor.c
```

## Usage

In order for the program to run, it must be executed with a positive semiprime integer as an argument:

```sh
./factor <semiprime>
```

## Demo

Example:

```sh
$ ./factor
Usage: ./factor <semiprime>
$ ./factor 9
Factors: 3 3
$ ./factor 46
Factors: 2 23
$ ./factor 93
Factors: 3 31
$ ./factor 9827348119
Factors: 613 16031563
```

## Technical Details

For the implementation, I considered the fact that all prime numbers are odd apart from 2. Therefore, I seperately checked if 2 is a factor and then checked for odd factors until $ \sqrt{semiprime} $.

In addition, if we find a prime factor *i* then the second factor is $ \frac{\text{semiprime}}{i} $, only if it is also a prime number.

In C code: 

```c
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
```

