#include <unistd.h>

static int	gm_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
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

void	gm_putnbr(int nbr)
{
	long	nb;
	char	digit;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb >= 10)
		gm_putnbr(nb / 10);
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	int	result;
	int	i;

	result = 0;
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		result = result + gm_atoi(argv[i]);
		i++;
	}
	gm_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
