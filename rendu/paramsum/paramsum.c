#include <unistd.h>

void fput(int n)
{
    char box[12];
    int i = 0;
    if (n == 0)
        write(1,"0",1);
    while (n > 0)
    {
        box[i] = n % 10 + '0';
        n /= 10;
        i++;
    }
    while (i--)
        write(1,&box[i],1);
}
int main(int ac,char **av)
{
    if (ac > 0)
    {
        int count = 0;
        int i = 0;
        while (i < ac)
        {
            i++;
            count++;
        }
        fput(count - 1);
        write(1,"\n",1);
    }
    else
        fput(0);
}
