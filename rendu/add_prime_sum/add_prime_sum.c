#include <unistd.h>


int ft_atoi(char *s)
{
    int i = 0, r = 0, d = 1;
    
    while (s[i] >= 9 && s[i] <= 13 || s[i] == ' ')
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            d = d * (-1);
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        r = r * 10 + s[i] - '0';
        i++;
    }
    return d * r;
}
void fputnbr(int nb)
{
    char box[12];
    int i = 0;
    long n = nb;

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
int is_prime(int n)
{
    int  i = 2;
    while (i < n && i > 0)
    {
        if (n % i  == 0)
            return 0;
        i++;
    }
    return 1;
}       
int main(int ac,char **av)
{
    if (ac == 2)
    {
        int num = ft_atoi(av[1]);

        int i = 0;
        int total = 0;
        while (num > 0)
        {
            if (is_prime(num) == 1)
                total = total + num;
            num--;
        }
        fputnbr(total -1);
        write(1,"\n",1);
    }
    else
    {
        fputnbr(0);
        write(1,"\n",1);
    }
}
