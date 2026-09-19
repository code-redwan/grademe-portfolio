#include <unistd.h>

int	main(void)
{
	char	c;
	char	nc;

	c = 'a';
	while (c <= 'z')
	{
		if (c % 2 == 0)
		{
			nc = c - 32;
			write(1, &nc, 1);
			write(1, &nc, 1);
		}
		else
		{
			write(1, &c, 1);
			write(1, &c, 1);
		}
		c++;
	}
	write(1, "\n", 1);
	return (0);
}
