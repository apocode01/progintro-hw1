#include <stdio.h>
#include <stdlib.h>

long long gcd(long long num1,long long num2) {
    long long division_remainder = num1 % num2;
    if (division_remainder == 0) {
        return num2;
    }
    else {
        return gcd(num2,division_remainder);
    }
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n",argv[0]);
        return 1;
    }
    long long num1 = atoll(argv[1]);
    long long num2 = atoll(argv[2]);
    long long result = gcd(num1,num2);
    if (result < 0) {
        result *= -1;
    }
    printf("gcd(%lld, %lld) = %lld\n",num1,num2,result);
    return 0;
}