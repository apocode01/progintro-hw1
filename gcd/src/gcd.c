#include <stdio.h>
#include <stdlib.h>

/* 
 - Filename: gcd.c
 - Author: Apostolos Panousakis
 - Description: A program that simulates the Euclidean Algorithm and calculates the greatest common divisor (GCD) of two numbers.
*/

// Declare the gcd function
long long gcd(long long num1,long long num2);

int main(int argc, char * argv[]) {
    // Check if the user has provided 3 arguments (including program name)
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n",argv[0]);
        return 1; // Unsuccessful termination with exit code 1
    }

    // Convert the arguments to the long long variable type
    long long num1 = atoll(argv[1]);
    long long num2 = atoll(argv[2]);

    // Check if the user has given non-zero integers for arguments
    if (num1 == 0 || num2 == 0) {
        printf("Usage: %s <num1> <num2>\n",argv[0]);
        return 1; // Unsuccessful termination with exit code 1
    }

    // Call the gcd function and assign its value to the result variable
    long long result = gcd(num1,num2);

    // Find the absolute value of the GCD
    if (result < 0) {
        result *= -1;
    }

    printf("gcd(%lld, %lld) = %lld\n",num1,num2,result);
    return 0; // Successful termination with exit code 0
}

// Calculate the GCD using the Euclidian Algorithm and recursion
long long gcd(long long num1,long long num2) {
    long long division_remainder = num1 % num2;
    if (division_remainder == 0) {
        return num2;
    }
    else {
        return gcd(num2,division_remainder);
    }
}