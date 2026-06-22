#include <unistd.h>

void display(char *s, char *s1)
{
    int i = 0;
    int j = 0;

    while (s[i] && s1[j])
    {
       
        if (s[i] == s1[j])
            i++;
        j++;
    }
    if (s[i] == '\0')
        write(1,"1\n",2);
    else
        write(1,"0\n",2);
  
}
int main(int ac,char **av)
{
    if (ac == 3)
        display(av[1],av[2]);
    else
        write(1,"\n",1);
}
