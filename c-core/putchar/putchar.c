#include <unistd.h>

int	gm_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return(-1);
	return (c);
}
