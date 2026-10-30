#include <unistd.h>

static unsigned int	gm_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

static void	gm_putstr(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	int	is_rev;

	if (argc != 4)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	if ((gm_strlen(argv[2]) != 1) || (gm_strlen(argv[3]) != 1))
	{
		write(1, "\n", 1);
		return (0);
	}
	len = gm_strlen(argv[1]);
	i = 0;
	is_rev = 0;
	while (i <= len && is_rev == 0)
	{
		if (argv[1][len] == argv[2][0])
		{
			argv[1][len] = argv[3][0];
			is_rev = 1;
		}
		len--;
	}
	gm_putstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}

