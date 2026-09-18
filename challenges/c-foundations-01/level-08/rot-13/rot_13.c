#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	i = 0;
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			c = (argv[1][i] - 'a') + 13;
			c = (c % 26) + 'a';
			write(1, &c, 1);
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			c = (argv[1][i] - 'A') + 13;
			c = (c % 26) + 'A';
			write(1, &c, 1);
		}
		else
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
