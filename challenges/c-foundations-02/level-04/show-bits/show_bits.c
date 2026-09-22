#include <unistd.h>

static void	ft_putnbr_bite(int nbr)
{
	long	nb;
	char	*binary = "01";

	nb = nbr;
	if (nb >= 2)
		ft_putnbr_bite(nb / 2);
	write(1, &binary[nb % 2], 1);
}

static int	digit_count(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 2;
		count++;
	}
	return (count);
}

void	show_bits(unsigned int byte)
{
	int	len;

        len = 8 - digit_count(byte);
        while (0 < len)
        {
        	write(1, "0", 1);
        	len--;
        }
	ft_putnbr_bite(byte);
}
