#include <unistd.h>

void	ft_mini_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_mini_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int		i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			if (i % 3 == 0)
				write(1, "Fizz", 4);
			if (i % 5 == 0)
				write(1, "Buzz", 4);
		}
		else
			ft_mini_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
