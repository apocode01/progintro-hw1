#include <stdio.h>
#include <stdlib.h>

int is_prime(long long num);

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <semiprime>\n",argv[0]);
        return 1;
    }

    long long semiprime = atoll(argv[1]);

    if ( is_prime(semiprime/2) && 2*(semiprime/2)==semiprime ) {
        printf("Factors: %d %lld\n",2,semiprime/2);  
        return 0;
    }
    
    for (long long i = 3 ; i*i<=semiprime ; i += 2) {
        if ( is_prime(i) && semiprime%i==0 ) {
            printf("Factors: %lld %lld\n",i,semiprime/i);  
            return 0;
        } 
    }

    printf("Not a semiprime\n");
    return 1;
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