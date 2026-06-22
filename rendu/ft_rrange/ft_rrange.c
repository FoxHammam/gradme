#include <stdlib.h>
#include <stdio.h>


int     *ft_rrange(int start, int end)
{
    int max;
    if (start <= end)
        max = end - start + 1;
    else
        max = start - end + 1;
    int *d = malloc(sizeof(int) * (max));
    if (!d)
        return 0;
    int i = 0 ;
    while (i < max)
    {
        d[i] = end;
        if (end > start)
            end--;
        else
            end++;
        i++;

    }
    return d;
}
