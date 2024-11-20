#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, char * argv[]) {
    if (argc != 6) {
        printf("Usage: %s enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n",argv[0]);
        return 1;
    }

    char *op = argv[1];
    if (strcmp(op,"enc")!=0 && strcmp(op,"dec")!=0) {
        printf("First argument must be 'enc' or 'dec'\n");
        return 1;
    }

    long long e = atoll(argv[2]);
    long long d = atoll(argv[3]);
    long long p = atoll(argv[4]);
    long long q = atoll(argv[5]);

    if ( e<0 || d<0 || p<0 || q<0 ) {
        printf("Negative numbers are not allowed\n");
        return 1;
    }

    if (is_prime(p) == 0 || is_prime(q) == 0) {
        printf("p and q must be prime\n");
        return 1;   
    }

    long long m;
    scanf("%lld",&m);
    long long N = p * q;

    if (m>=N) {
        printf("Message is larger than N\n");
        return 1;
    }

    if (m<0) {
        printf("Negative numbers are not allowed\n");
        return 1;   
    }
    return 0;
}