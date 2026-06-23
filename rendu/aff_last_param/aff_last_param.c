#include <unistd.h>

int fs(char *s)
{
	int i =0;
	while ( s[i])
		i ++;
	return i;
}
int main(int ac, char **av)
{
	if (ac  > 1)
	{	
		write(1, av[ac - 1], fs(av[ac - 1]));
		write(1, "\n", 1);
	}
	else
	{
		write(1, "\n", 1);
	}
}
