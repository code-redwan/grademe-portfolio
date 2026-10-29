#include <unistd.h>

static int	gm_mini_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (result >= 0 && result <= 9)
		return (result);
	return (0);
}

static void	gm_mini_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		gm_mini_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	digit;
	int	i;
	int	temp;

	if (argc != 2)
	{
		write (1, "wrong number of arguments\n", 26);
		return (0);
	}
	digit = gm_mini_atoi(argv[1]);
	if (digit == 0)
		return (0);
	i = 1;
	while (i <= 9)
	{
		temp = i + '0';
		write(1, &temp, 1);
		write(1, " x ", 3);
		write(1, &argv[1][0], 1);
		write(1, " = ", 3);
		temp = i * digit;
		gm_mini_putnbr(temp);
		write(1, "\n", 1);
		i++;
	}
}
