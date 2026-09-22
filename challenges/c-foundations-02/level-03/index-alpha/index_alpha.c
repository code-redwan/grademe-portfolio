#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	while (argv[1][i])
	{
		if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				len = argv[1][i] - 'A';
			else
				len = argv[1][i] - 'a';
			while (0 < len)
		        {
			    write(1, &argv[1][i], 1);
			    len--;
		        }
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
