#include <unistd.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int		len;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	len = ft_strlen(argv[1]);
	while (0 < len)
	{
		write(1, &argv[1][len - 1], 1);
		len--;
	}
	write(1, "\n", 1);
	return (0);
}
