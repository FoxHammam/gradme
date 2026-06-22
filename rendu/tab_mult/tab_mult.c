#include <unistd.h>
#include <stdio.h>
void ft_putnbr(int nb)
{
	char box[10];
	long n;

	n = nb;
	if (n == 0)
	{
		write(1,"0",1);
		return ;
	}
	int i = 0;
	while (n > 0)
	{
		box[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (i--)
		write(1,&box[i],1);
}
int ft_atoi(char *str)
{
	int i = 0;
	int s = 1;
	int r = 0;

	while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (s * r);
}
int main(int ac,char **av)
{
	if (ac == 2)
	{
		int num = ft_atoi(av[1]);
		int i =1;
		int total = 0;
		while (i < 10)
		{
			total = i * num;
			ft_putnbr(i);
			write(1," x ",3);
			ft_putnbr(num);
			write (1," = ",3);
			ft_putnbr(total);
			write(1,"\n",1);
			i++;
		}
	}
	else
		write (1,"\n",1);
}
