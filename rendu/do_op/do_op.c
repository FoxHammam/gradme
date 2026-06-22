#include <stdio.h>
#include <stdlib.h>

int main(int ac,char **av)
{
    if (ac == 4)
    {
        long num = atoi(av[1]);
        long num1 = atoi(av[3]);
        long total = 0;
         if (*av[2] == '*')
            total = num * num1;
        else if (*av[2] == '-')
            total = num - num1;
        else if (*av[2] == '+')
            total = num + num1;
        else if (*av[2] == '/')
            total = num / num1;
        else if (*av[2] == '%')
            total = num % num1;
        printf("%ld\n",total);
    }
    else
        printf("\n");
}
