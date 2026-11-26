#include <unistd.h>

int	is_palindrome(char* start, char* end)
{
	while (start <= end)
	{
		if (*start != *end)
			return (0);
		start++;
		end--;
	}
	return (1);
}

int	gm_strlen(char* string)
{
	int	len;

	len = 0;
	while (*(string + len))
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	int	x_len;
	int max_len;
	int current_len;
	int start_pos;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	len = gm_strlen(argv[1]);
	max_len = 0;
	start_pos = 0;
	x_len = 0;
    while (x_len < len)
	{
		i = x_len;
		while (argv[1][i])
		{
			if (is_palindrome(&argv[1][x_len], &argv[1][i]) == 1)
			{
				current_len = i - x_len + 1;
				if (current_len > max_len)
				{
    				max_len = current_len;
    				start_pos = x_len;
				}
			}
			i++;
		}
		x_len++;
	}
	write(1, &argv[1][start_pos], max_len);
	write(1, "\n", 1);
	return (0);
}
