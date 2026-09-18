#include <stdlib.h>
#include <unistd.h>

// argv[1] is the width, argv[2] the height. Draw the frame of that rectangle:
// '+' corners, '-' on top and bottom, '|' on the sides, spaces inside.
void	print(int col, char c, char cc)
{
	int		i;

	i = 1;
	while (i <= col)
	{
		if (i == 1 || i == col)
			write(1, &c, 1);
		else
			write(1, &cc, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	int		i;

	if (argc != 3)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	if (width <= 0 || height <= 0)
		return (0);
	i = 1;
	while (i <= height)
	{
		if (i == 1 || i == height)
			print(width, '+', '-');
		else
			print(width, '|', ' ');
		i++;
	}
	return (0);
}
