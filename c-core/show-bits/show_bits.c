#include <unistd.h>

static void    ft_putbits(unsigned char byte)
{
    char    *base = "01";

    if (byte >= 2)
        ft_putbits(byte / 2);
    write(1, &base[byte % 2], 1);
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

void show_bits(unsigned char byte)
{
    int     len;

    len = 8 - digit_count(byte);
    while (0 < len)
    {
        write(1, "0", 1);
        len--;
    }
    ft_putbits(byte);
}