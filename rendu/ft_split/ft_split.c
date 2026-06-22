#include <stdlib.h>
#include <stdio.h>


char **ft_split(char *str)
{
    int i = 0, j = 0, k = 0;
    char **box = malloc(sizeof(char *) * 2096);
    if (!box)
        return NULL;
    while (str[i])
    {
        while (str[i] && str[i] <= 32)
            i++;
        if (!str[i])
            break;
        box[j] = malloc(4096);
        if (!box[j])
            return NULL;
        k = 0;
        while (str[i] && str[i] > 32)
            box[j][k++] = str[i++];
        box[j][k] = '\0';
        j++;
    }
    box[j] = NULL;
    return box;
}
