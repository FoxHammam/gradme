#include <stdio.h>
#include <stdlib.h>

void fprime(unsigned int n)
{
    unsigned int i = 0;

    if (n == 1)
        printf("1");
    else
    {
        i = 2;

        while (n > 1)
        {
            if (n % i == 0)
            {
                printf("%d",i);
                n /= i;
                if (n > 1)
                    printf("*");
            }
            else
                i++;
        }
    }
}
int main(int ac,char **av)
{
    if (ac == 2)
    {
        int n = atoi(av[1]);
        if (n < 0)
            printf("\n");
        else
        {
            fprime((unsigned int)n);
            printf("\n");
        }
    }
    else
        printf("\n");
}


