#include <unistd.h>

int	main(void)
{
	char alpha;
	alpha = '9';
	while(alpha >= '0')
	{
		write(1, &alpha, 1);
		alpha--;
	}
	write(1, "\n", 1);
	return (0);
}
