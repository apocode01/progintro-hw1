#include <stdio.h>
#include <string.h> // For the strcmp() function
#include <stdlib.h> // For the atoll() function

/* 
 - Filename: gcd.c
 - Author: Apostolos Panousakis
 - Description: A program that encrypts and decrypts messages using the RSA algorithm.
*/

// Declare all functions
int is_prime(long long num);
long long gcd(long long num1,long long num2);
long long phi(long long num1,long long num2);
long long mod_exp(long long base,long long exponent,long long mod);

int main(int argc, char * argv[]) {
    // Check if the user has provided 6 arguments (including program name)
    if (argc != 6) {
        printf("Usage: %s enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n",argv[0]);
        return 1;
    }

    // Check if the second argument (op) is neither "enc" or "dec"
    char *op = argv[1];
    if (strcmp(op,"enc")!=0 && strcmp(op,"dec")!=0) {
        printf("First argument must be 'enc' or 'dec'\n");
        return 1;
    }

    // Convert the arguments to the long long variable type
    long long e = atoll(argv[2]);
    long long d = atoll(argv[3]);
    long long p = atoll(argv[4]);
    long long q = atoll(argv[5]);

    // Check if the 3rd, 4th, 5th and 6th arguments (e, d, p and q) are negative
    if ( e<0 || d<0 || p<0 || q<0 ) {
        printf("Negative numbers are not allowed\n");
        return 1;
    }

    // Check if the 5th and 6th arguments (p and q) are not prime numbers by calling the is_prime function
    if (!is_prime(p) || !is_prime(q)) {
        printf("p and q must be prime\n");
        return 1;   
    }

    long long N = p * q;

    // Calulcate φ(N) by calling the phi function with p and q as parameters
    long long phi_N = phi(p,q);

    // Check if e is not coprime with φ(N) by verifying if their GCD is not 1
    if (gcd(e,phi_N) != 1) {
        printf("e is not coprime with phi(N)\n");
        return 1;
    }

    // Check if e · d mod φ(N) is not 1
    if ((e*d)%phi_N != 1) {
        printf("e * d mod phi(N) is not 1\n");
        return 1;
    } 

    // Read the message m from standard input and check if the user has given EOF
    long long m;
    if (scanf("%lld",&m) != 1) {
        return 1;
    }
    
    // Check if the message m is larger or the same length as N
    if (m>=N) {
        printf("Message is larger than N\n");
        return 1;
    }

    // Check if the message m is a negative number
    if (m<0) {
        printf("Negative numbers are not allowed\n");
        return 1;   
    }

    // Encrypt or decrypt the message
    if (strcmp(op,"enc")==0) {
        printf("%lld\n",mod_exp(m,e,N)); 
    }
    else {
        printf("%lld\n",mod_exp(m,d,N));   
    }
    return 0;
}

// The is_prime function returns 0 if a number is not prime and 1 if a number is prime
int is_prime(long long num) {
    if (num<=1 || (num!=2 && num%2==0)) {
        return 0;
    }
    // Number 2 is the only even prime number
    else if (num==2) {
        return 1;
    }
    for (long long i = 3 ; i*i<=num ; i+=2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// The gcd function calculates the GCD of two numbers using the Euclidian Algorithm and recursion
long long gcd(long long num1,long long num2) {
    long long division_remainder = num1 % num2;
    if (division_remainder == 0) {
        return num2;
    }
    else {
        return gcd(num2,division_remainder);
    }
}

// The phi function calculates the value φ(N) where N is the product of two prime numbers
// Since φ(a·b) = φ(a)·φ(b) and φ(c) = c-1 for any prime number c then the function only has to calculate: φ(Ν) = φ(num1 · num2) = (num1-1)·(num2-1) 
long long phi(long long num1,long long num2) {
    return (num1-1)*(num2-1);
}

// The mod_exp function calculates the value (a^b) mod c for any positive number a, b and c
// This function uses a very efficient modular exponentiation algorithm to reduce the number of operations
long long mod_exp(long long base,long long exponent,long long mod) {
    if (mod == 1)
        return 0; // Any number mod 1 is always 0
    long long result = 1;
    base = base % mod; // Reduce base to prevent unnecessary large values
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod; 
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }
    return result;
}