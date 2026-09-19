#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			index = (argv[1][i] - 'a') % 26;
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			index = (argv[1][i] - 'A') % 26;
		else
			write(1, &argv[1][i], 1);
		while (0 != index)
		{
			write(1, &argv[1][i], 1);
			index--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
