#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write(1,&c,1);
	return (1);
}
int ft_putstr(char *s)
{
	int i = 0;
	if (!s)
	{
		write(1,"(null)",6);
		return (6);
	}
	while (s[i])
	{
		write(1,&s[i],1);
		i++;
	}
	return (i);
}
int cal_len(int nb)
{
	int len = 0;
	long n = nb;
	
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
int ft_putnbr(int nb)
{
	long n;
	char box[12];
	
	n = nb;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	int i = 0;
	while (n > 0)
	{
		box[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (--i >= 0)
		write(1,&box[i],1);
	return (cal_len(nb));
}
int cal_len1(unsigned long nb)
{
	long len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int put_hex(unsigned int nb,char *s)
{
	int i = 0;
	char box[32];
	int len = cal_len1(nb);
	if (nb == 0)
	{
		write(1,"0",1);
		return 1;
	}
	while (nb > 0)
	{
		box[i] = s[nb % 16];
		nb /= 16;
		i++;
	}
	while (--i >=0)
		write(1,&box[i],1);
	return (len);
}

int display(const char *s, va_list *arg)
{
	int i = 0;
	if (*s == 'c')
		i = ft_putchar(va_arg(*arg, int));
	else if (*s == 's')
		i = ft_putstr(va_arg(*arg, char *));
	else if (*s == 'i' || *s == 'd')
		i = ft_putnbr(va_arg(*arg, int));
	else if (*s == 'x')
		i = put_hex(va_arg(*arg ,unsigned int),"0123456789abcdef");
	return (i);
}
int ft_printf(const char *s, ...)
{
	va_list arg;
	int j = 0;
	
	va_start(arg, s);
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				j += ft_putchar('%');
			else if(*s)
				j += display(s,&arg);
		    s++;	
		}
		else
			j += ft_putchar(*s++);
	}
	va_end(arg);
	return(j);
}
/*
int main()
{
	 ft_printf("%d\n",ft_printf("%% |%s| |%d| |%x|  |%c|\n","hamza",-42,42,'r'));
	   printf("%d\n" ,   printf("%% |%s| |%d| |%x|  |%c|\n"  ,"hamza",-42,42,'r'));
}
*/
