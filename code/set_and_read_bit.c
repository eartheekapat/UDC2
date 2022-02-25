// setting and reading bits

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototype
long long convert_dec_to_bin(int n);
int checkBit(int n, int pos);
long long setBit(int n, int pos);
int convert_bin_to_dec(long long n);

int main()
{
    int n;
    int pos;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("Enter nth bit to check and set : ");
    scanf("%d", &pos);

    int res = checkBit(n, pos);
    printf("bit %d of %d in bin is %d\n", pos, n, res);

    // now that we want to set bit
    if (res == 0)
    {
        printf("we set position %d of %d in bin to 1\n", pos, n);
        printf("which makes it becomes %d in dec which is %lld in bin\n",
               convert_bin_to_dec(setBit(n, pos)), setBit(n, pos));
    }

    return 0;
}

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

long long setBit(int n, int pos)
{
    long long bin = convert_dec_to_bin(n);
    int multiplier = 1;
    for (int i = 0; i < pos - 1; i++)
        multiplier *= 10;
    return bin + multiplier;
}

int checkBit(int n, int pos)
{
    long long bin = convert_dec_to_bin(n);
    for (int i = 0; i < pos - 1; i++)
    {
        bin = bin / 10;
    }
    return bin % 10;
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