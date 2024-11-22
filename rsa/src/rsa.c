#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_prime(long long num);
long long gcd(long long num1,long long num2);
long long phi(long long num);
long long bob(long long base,long long exponent,long long mod);

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

    if (!is_prime(p) || !is_prime(q)) {
        printf("p and q must be prime\n");
        return 1;   
    }

    long long N = p * q;

    long long phi_N = phi(N);

    if (gcd(e,phi_N) != 1) {
        printf("e is not coprime with phi(N)\n");
        return 1;
    }

    if ((e*d) % phi_N != 1) {
        printf("e * d mod phi(N) is not 1\n");
        return 1;
    } 

    long long m;
    if (scanf("%lld",&m) != 1) {
        return 1;
    }
    
    if (m>=N) {
        printf("Message is larger than N\n");
        return 1;
    }

    if (m<0) {
        printf("Negative numbers are not allowed\n");
        return 1;   
    }
    printf("%lld\n",bob(m,e,N));
    return 0;
}

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

long long gcd(long long num1,long long num2) {
    long long division_remainder = num1 % num2;
    if (division_remainder == 0) {
        return num2;
    }
    else {
        return gcd(num2,division_remainder);
    }
}

// we dont have to check when num is prime
long long phi(long long num) {
    long long count = 0;
    for (long long i = 1 ; i<num ; i++) {
        if (gcd(i,num)==1) {
            count++;
        }
    }
    return count;
}

long long bob(long long base,long long exponent,long long mod) {
    long long result = 1;
    for (long long i=1 ; i<=exponent ; i++) {
        result = (base*result) % mod; 
    }
    return result;
}