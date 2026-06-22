#include <unistd.h>
#include <stdio.h>
int fdup(char *s, char c)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return 1;
        i++;
    }
    return 0;
}
int kl(char *s, int j)
{
    int i = 0;
    while (i < j)
    {
        if (s[i] == s[j])
            return 1;
        i++;
    }
    return 0;
}
void display(char *s, char *s1)
{
    int i = 0;
    int j = 0;

    while (s[i])
    {
        if (!(kl(s,i)) && (fdup(s1,s[i])))
            write(1,&s[i],1);
        i++;
    }
    write(1,"\n",1);
}

int main(int ac, char **av)
{
    if (ac == 3)
        display(av[1], av[2]);
    else
        write(1,"\n",1);
}
