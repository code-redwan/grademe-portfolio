#include <unistd.h>

# define ARG  1

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(ARG, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 0;
	while  (argv[ARG][i])
	{
		if (argv[ARG][i] >= 'a' && argv[ARG][i] <= 'z')
			argv[ARG][i] -= 32;
		else if (argv[ARG][i] >= 'A' && argv[ARG][i] <= 'Z')
			argv[ARG][i] += 32;
		write(ARG, &argv[ARG][i], ARG);
		i++;
	}
	write(ARG, "\n", ARG);
	return (0);
}
