#include <unistd.h>

static void	gm_clean_words(char *str)
{
	int	space;

	space = -1;
	while (*str)
	{
		if ((*str == ' ' || *str == '\t') && space != -1)
			space = space + 1;
		if (*str != ' ' && *str != '\t')
		{
			if (space > 0)
				write(1, " ", 1);
			write(1, str, 1);
			space = 0;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	gm_clean_words(argv[1]);
	write(1, "\n", 1);
	return (0);
}
