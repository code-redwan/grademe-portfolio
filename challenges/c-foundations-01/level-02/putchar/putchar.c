#include <unistd.h>

int	putchar(char c)
{
	unsigned int	byte;

	byte = (unsigned int) c;
	write (1, &byte, 1);
	return (byte);
}
