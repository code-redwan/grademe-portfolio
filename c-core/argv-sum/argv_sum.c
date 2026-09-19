#include <unistd.h>

int		ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * (-1);
	}
	if (nbr >=10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int		sum;
	int		index;

	sum = 0;
	index = 1;
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (index < argc)
	{
		sum = sum + ft_atoi(argv[index]);
		index++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}