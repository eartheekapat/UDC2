// convert binary to decimal

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototype
int convert_bin_to_dec(long long n);

int main()
{
    long long n;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    printf("%lld in binary = %d in decimal\n", n,
           convert_bin_to_dec(n));

    return 0;
}

// function definition
int convert_bin_to_dec(long long n)
{
    int base = 1;
    int retVal = 0;
    int last_digit;
    while (n > 0)
    {
        last_digit = n % 10;
        retVal = retVal + last_digit * base;
        base = base * 2;
        n = n / 10;
    }
    return retVal;
}
