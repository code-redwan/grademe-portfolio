#include <unistd.h>

// argv[1] holds only decimal digits, worth 0 to 1000000000.
// Print twice that value, then a newline.

int	gm_mini_atoi(char *str)
{
	int result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result);
}

void	gm_mini_putnbr(int nb)
{
	int	c;

	if (nb >= 10)
		gm_mini_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	number = gm_mini_atoi(argv[1]);
	gm_mini_putnbr(number * 2);
	write(1, "\n", 1);
	return (0);
}
