#include <unistd.h>

static void	gm_putchar(const char c)
{
	write(1, &c, 1);
}

static long gm_atoi(const char *str)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
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

static void	gm_puthex(long number)
{
    char*   base;

    base = "0123456789abcdef";
    if (number >= 16)
		gm_puthex(number / 16);
    gm_putchar(base[number % 16]);
}

int	main(int argc, char **argv)
{
	long	number;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	number = gm_atoi(argv[1]);
	if (number < 0)
		return (0);
	gm_puthex(number);
	gm_putchar('\n');
	return (0);
}
