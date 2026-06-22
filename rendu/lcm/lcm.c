#include <stdio.h>
#include <limits.h>
unsigned int pgcd(unsigned int num, unsigned int num1)
{
    unsigned int i = num;

    while (i > 0)
    {
        if (num % i == 0 && num1 % i == 0)
            return i;
        i--;
    }
    return 1;
}
unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int total =0;

    if (a < 0 || b < 0 || a > INT_MAX || b > INT_MAX)
        return 0;
    total = (a * b) / pgcd(a,b);
    return total;
}
