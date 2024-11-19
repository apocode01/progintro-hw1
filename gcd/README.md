## The Euclidean Algorithm

The Euclidean Algorithm is an ancient and efficient method for finding the Greatest Common Divisor (GCD) of two integers:

$$
\text{gcd}(a, b) =
\begin{cases}
b & \text{if } a \mod b = 0 \\
\text{gcd}(b, a \mod b) & \text{otherwise}
\end{cases}
$$

The purpose of this program is to simulate the Euclidean Algorithm and find the GCD of two integers.

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
gcc -O3 -Wall -Wextra -Werror -pedantic -o gcd gcd.c
```

## Usage

In order for the program to run, it must be executed with two non-zero integers as arguments:

```sh
./gcd <num1> <num2>
```

## Demo

Example:

```sh
$ ./gcd 36 7
gcd(36, 7) = 1
$ ./gcd -42 9
gcd(-42, 9) = 3
$ ./gcd 1 2 3
Usage: ./gcd <num1> <num2>
```

## Technical Details

For the implementation, I made the assumption that if the user does not give 2 non-zero integers for arguments then the program prints an appropriate message. 

Check if the user has provided 3 arguments (including program name):

```sh
if (argc != 3) {
    printf("Usage: %s <num1> <num2>\n",argv[0]);
    return 1;
}
```

Check if the user has given non-zero integers for arguments (if the user gives a set of characters for an argument then the `atoll` function will convert them to the number 0):

```sh
long long num1 = atoll(argv[1]);
long long num2 = atoll(argv[2]);
if (num1 == 0 || num2 == 0) {
    printf("Usage: %s <num1> <num2>\n",argv[0]);
    return 1;
}
```
