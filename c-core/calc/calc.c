#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		number_1;
	int		number_2;
	int		result;

	if (argc != 4)
	{
		printf("wrong number of arguments\n");
		return (0);
	}
	number_1 = atoi(argv[1]);
	number_2 = atoi(argv[3]);
	if (argv[2][0] == '+')
		result = (number_1 + number_2);
	else if (argv[2][0] == '-')
		result = (number_1 - number_2);
	else if (argv[2][0] == '*')
		result = (number_1 * number_2);
	else if (argv[2][0] == '/')
		result = (number_1 / number_2);
	else if (argv[2][0] == '%')
		result = (number_1 % number_2);
	printf("%d\n", result);
	return (0);
}
