#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;
	int	found;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 0;
	start = 0;
	end = 0;
	found = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			start = i;
			found = 1;
		}
		i++;
	}
	end = start;
	while (start > 0 && argv[1][start - 1] != ' ' && argv[1][start - 1] != '\t')
		start--;
	while (found == 1 && start <= end)
		write(1, &argv[1][start++], 1);
	write(1, "\n", 1);
	return (0);
}
