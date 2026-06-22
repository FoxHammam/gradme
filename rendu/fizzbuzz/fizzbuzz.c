#include<unistd.h>

void fput(int n)
{
    char box[12];
    int i = 0;

    while (n >0)
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
    int i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1,"fizzbuzz\n",9);
        else if(i % 5 == 0)
            write(1,"buzz\n",5);
        else if (i % 3 == 0)
            write(1,"fizz\n",5);
        else
        {
            fput(i);
            write(1,"\n",1);
        }
        i++;
    }
}

