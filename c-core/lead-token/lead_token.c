#include <unistd.h>

static const char	*skip_spaces(const char *s)
{
	while (*s == '\t' || *s == ' ')
		s++;
	return (s);
}

int	main(int argc, char **argv)
{
	const char		*string;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	string = skip_spaces(argv[1]);
	while (*string)
	{
		if (*string == ' ')
		{
			write(1, "\n", 1);
			return (0);
		}
		write(1, string, 1);
		string++;
	}
	write(1, "\n", 1);
	return (0);
}
