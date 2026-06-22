#include <unistd.h>

void display(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'y')
        {
            s[i] = 'z' - s[i] + 'a';
            write(1,&s[i],1);
        }
        else if (s[i] >= 'A' && s[i] <= 'Y')
        {
            s[i] = 'Z' - s[i] + 'A';
            write(1,&s[i],1);
        }
        else if (s[i] == 'z')
            write(1,"a",1);
        else if (s[i] == 'Z')
            write(1,"A",1);
        else
            write(1,&s[i],1);
        i++;
    }
    write(1,"\n",1);
}
int main(int ac,char **av)
{
    if ( ac == 2)
        display(av[1]);
    else
        write(1,"\n",1);
}