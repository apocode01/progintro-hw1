## The RSA Algorithm

The RSA algorithm is a widely used cryptographic system for secure data transmission. It’s named after its inventors, Rivest, Shamir, and Adleman. One of its purposes is to encrypt and decrypt messages.

The purpose of this program is to simulate the RSA Algorithm and use it for encryption and decryption.

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
gcc -O3 -Wall -Wextra -Werror -pedantic -o rsa rsa.c
```

## Usage

In order for the program to run, it must be executed with:

1) One argument being either 'enc' (for encryption) or 'dec' (for decryption)
2) Four more arguments being positive integers
- Constraint: the message m must be less than N = p·q.
- Constraint: the integers p and q are prime.
- Constraint: the integer e is coprime with ϕ(N).
- Constraint: the integers e and d are inverses, that is: e · d mod ϕ(N) = 1.
3) One positive integer via stdin

```sh
./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>
```

## Demo

Example:

```sh
$ ./rsa
Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>
$ ./rsa pop 1 2 3 4
First argument must be 'enc' or 'dec'
$ ./rsa enc -1 2 3 4
Negative numbers are not allowed
$ ./rsa enc 1 2 3 4
p and q must be prime
$ ./rsa enc 3 6 17 19
e is not coprime with phi(N)
$ ./rsa enc 5 6 17 19
e * d mod phi(N) is not 1
$ echo 350 | ./rsa enc 5 173 17 19
Message is larger than N
$ echo -50 | ./rsa enc 5 173 17 19
Negative numbers are not allowed
$ echo 42 | ./rsa enc 17 26153 131 229
27187
$ echo 27187 | ./rsa dec 17 26153 131 229
42
```

## Technical Details

For the implementation, I created the ```long long phi(long long num1,long long num2)``` function which only returns ```(num1-1)*(num2-1)``` because:

1) φ(a·b) = φ(a)·φ(b)
2) φ(c) = c-1 for any prime number c

So combining these together we have: φ(Ν) = φ(num1 · num2) = (num1-1) · (num2-1), where num1 and num2 are prime numbers

Code: 

```c
long long phi(long long num1,long long num2) {
    return (num1-1)*(num2-1);
}
```

I also used a ```long long mod_exp(long long base,long long exponent,long long mod)``` function that calculates the value (a^b) mod c for any positive number a, b and c.

This function uses a very efficient modular exponentiation algorithm to reduce the number of operations.

Code: 

```c
long long mod_exp(long long base,long long exponent,long long mod) {
    if (mod == 1)
        return 0; 
    long long result = 1;
    base = base % mod; 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod; 
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }
    return result;
}
```