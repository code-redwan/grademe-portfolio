#include <stdlib.h>
#include <unistd.h>

// argv[1] is the height. Print a centered pyramid of '#', one row per line.
// A wrong argument count prints "wrong number of arguments" and a newline.

static void	print(unsigned char c, unsigned int count)
{
	while (count > 0)
	{
		write(1, &c, 1);
		count--;
	}	
}

int	main(int argc, char **argv)
{
	int	number;
	int	i;
	int	spaces;
	int	hashs;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	number = atoi(argv[1]);
	i = 1;
	while (i <= number)
	{
		spaces = number - i;
		hashs = number - spaces;
		print(' ',spaces);
		hashs = hashs + (hashs - 1);
		print('#', hashs);
		hashs++;
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
