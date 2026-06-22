#include <unistd.h>
#include <stdio.h>

long int flen(int nb)
{
	int len = 0;

	if (nb <= 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
char *display(char *box,int nb,long int len)
{
	while (nb > 0)
	{
		box[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (box);
}
char *ft_itoa(int nbr)
{
	unsigned int slen = flen(nbr);
	char *new;
	int long n;
	
	new = malloc(sizeof(char) * slen + 1);
	if (!new)
		return (NULL);
	new[slen--] = '\0';
	if (nbr < 0)
	{
		n = nbr * (-1);
		new[0] = '-';
	}
	if (nbr == 0)
	{
		new[0] = '0';
	}
	else
		n = nbr;
		new = display(new,n,slen);
	return(new);
}


	

