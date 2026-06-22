#include <unistd.h>
#include <stdio.h>
int long ft_atoi(char *s)
{
	int i = 0;
	int t = 1;
	int r = 0;

	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			t = t * (-1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + s[i] - '0';
		i++;
	}
	return (t * r);
}
int main(int ac,char **av)
{
	if (ac == 2)
	{
		char box[32];
		char *hex = "0123456789abcdef";
		int long  num = ft_atoi(av[1]);

			int i = 0;
			while (num > 0)
			{
				box[i] = hex[num % 16];
				num /= 16;
				i++;
			}
			while (i--)
				write(1,&box[i],1);
			write(1,"\n",1);
	}
	else
		write(1,"\n",1);
}
