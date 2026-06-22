#include <unistd.h>

void display(char *s)
{
    int i = 0;
    int count = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            count = s[i] - 'a' + 1;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            count = s[i] - 'A' + 1;
        }
        else
            write(1,&s[i],1);

        while(count)
        {
            write(1,&s[i],1);
            count--;
        }
        i++;
    }
    write(1,"\n",1);
}
int main(int ac , char **av)
{
    if (ac == 2)
        display(av[1]);
    else
        write(1,"\n",1);
}
