#include <unistd.h>

static void	gm_folding(char *string)
{
	while (*string)
	{
		if (*string >= 'a' && *string <= 'z')
			*string = 'z' - (*string - 'a');
		write(1, string, 1);
		string++;
	}
}
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	gm_folding(argv[1]);
	write(1, "\n", 1);
	return (0);
}
