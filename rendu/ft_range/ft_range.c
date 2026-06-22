#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int max = 0;
    if (start <= end)
        max = end - start + 1;
    else
        max = start - end + 1;

    int *d = malloc(sizeof(int) * max);
    if (!d)
        return 0;
    int i = 0;
    while (i < max)
    {
        d[i] = start;
        if (end < start)
            start--;
        else
            start++;
        i++;
    }
    return d;
}