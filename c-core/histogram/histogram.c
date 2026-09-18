#include <stdlib.h>
#include <unistd.h>

// Each argument is one value. Print its bar: that many '#', then a newline.
// A value that is zero or negative gives an empty line, newline included.
int	main(int argc, char **argv)
{
	int		index;
	int		nested_index;

	index = 1; 
	if (argc < 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	while (index < argc)
	{
		nested_index = 0;
		while (nested_index < atoi(argv[index]))
		{
			write(1, "#", 1);
			nested_index++;
		}
		write(1, "\n", 1);
		index++;
	}
	return (0);
}
