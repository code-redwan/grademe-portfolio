#include <unistd.h>

static unsigned int	gm_strlen(const char *string)
{
	unsigned int	length;

	length = 0;
	while (*(string + length))
		length++;
	return (length);
}

int	main(int argc, char **argv)
{
	unsigned int	length;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	length = gm_strlen(argv[1]);
	while (0 != length)
	{
		write(1, &argv[1][length - 1], 1);
		length--;
	}
	write(1, "\n", 1);
	return (0);
}
