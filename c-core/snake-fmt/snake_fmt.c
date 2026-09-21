#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_upper(char c)
{
	if (c >= 'A' && c<= 'Z')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	while (argv[1][i])
	{
		if (ft_is_upper(argv[1][i]) == 1)
		{
			ft_putchar('_');
			ft_putchar(argv[1][i] + 32);
		}
		else
			ft_putchar(argv[1][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
