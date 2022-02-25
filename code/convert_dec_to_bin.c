// convert decimal to binary

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototype
long long convert_dec_to_bin(int n);

int main()
{
    int dec;
    printf("Enter a dec number: ");
    scanf("%d", &dec);
    printf("%d in dec = %lld in bin\n", dec,
           convert_dec_to_bin(dec));

    return 0;
}

long long convert_dec_to_bin(int n)
{
    int multiplier = 1;
    int rem;
    long long res = 0;
    while (n > 0)
    {
        rem = n % 2;
        res += rem * multiplier;
        multiplier *= 10;
        n = n / 2;
    }
    return res;
}
