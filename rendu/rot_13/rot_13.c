#include <unistd.h>

void display(char *s)
{
    int i = 0;
    while (s[i])
    {
        if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
        {
            s[i] += 13;
            write(1,&s[i],1);
        }
        else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
        {
            s[i] -= 13;
            write(1,&s[i],1);
        }
        else
            write(1,&s[i],1);
        i++;
    }
    write(1,"\n",1);
}
int main(int ac , char **av)
{
    if(ac == 2)
        display(av[1]);
    else
        write(1,"\n",1);
}

