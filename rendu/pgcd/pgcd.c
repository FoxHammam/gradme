#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int pgcd(unsigned int num, unsigned int num1)
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
int main(int ac,char **av)
{
    if (ac == 3)
    {
        int n = atoi(av[1]);
        int n1 = atoi(av[2]);

        if (n < 0 || n1 < 0 || n > INT_MAX || n1 > INT_MAX)
            return 0;
        else
            printf("%d\n",pgcd(n,n1));

    }
    else
        printf("\n");
}