#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    int i = 1;
    while (i <= n)
    {
        if (i * i == n)
            return 1;
        i++;
    }
    return 0;
}
