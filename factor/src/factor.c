#include <stdio.h>
#include <stdlib.h>

int is_prime(long long num);

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <semiprime>\n",argv[0]);
        return 1;
    }

    long long semiprime = atoll(argv[1]);

    for (long long i = 2 ; i<=semiprime/2+1 ; i = (i==2 ? 3 : i+2)) {
        for (long long j = 2 ; j<=semiprime/2+1 ; j = (j==2 ? 3 : j+2)) {
            if ( (is_prime(i) || is_prime(j)) && (i*j==semiprime) ) {
                printf("Factors: %lld %lld\n",i,j);
                return 0;
            }
        }
    }
    printf("Not a semiprime\n");
    return 0;
}

// The is_prime function returns 0 if a number is not prime and 1 if a number is prime
int is_prime(long long num) {
    if (num<=1) {
        return 0;
    }
    for (long long i = 2 ; i*i<=num ; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}