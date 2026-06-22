#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int b = str_base;

    if (b < 2 || b > 16)
        return 0;

    int i = 0;
    int r = 0;
    int s = 1;
    int val;

    while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            s = s * (-1);
        i++;
    }
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'f')
            val = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            val = str[i] - 'A' + 10;
        else if (str[i] >= '0' && str[i] <= '9')
            val = str[i] - '0';
        else
            break;

        if (val >= b)
            break;

        r = r * b + val;
        i++;
    }
    return r * s;
}
