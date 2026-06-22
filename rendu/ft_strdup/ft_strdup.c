#include <stdlib.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char    *ft_strdup(char *src)
{
    char *s;
    if (!(s = malloc(sizeof(char) * (ft_strlen(src) + 1))))
        return NULL;
    int i = 0;
    while (src[i])
    {
        s[i] = src[i];
        i++;
    }
    s[i] = '\0';
    return s;
 
}