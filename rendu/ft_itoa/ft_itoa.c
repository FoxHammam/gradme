#include <stdlib.h>
#include <stdio.h>

int flen(int n)
{
    int len = 0;
    if (n <= 0)
        len = 1;
    while (n)
    {
        len++;
        n /= 10;
    }
    return len;
}
char *ft_itoa(int nbr)
{
    int d = flen(nbr);
    long n = nbr;
    char *s;

    if (!(s = malloc(sizeof(char) * d + 1)))
        return NULL;
    s[d] = '\0';
    if (n < 0)
    {
        s[0] = '-';
        n = -n;
    }
    while (d-- > (nbr <0))
    {
        s[d] = n % 10 + '0';
        n /= 10;
    }
    return s;
}