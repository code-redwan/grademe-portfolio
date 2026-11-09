#include <stdlib.h>

static int	gm_abs(int number)
{
	if (number < 0)
		number = number * (-1);
	return (number);
}

int *int_range(int from, int to)
{
    int    len;
    int    *range;
    int    i;

    len = gm_abs(to - from) + 1;
    range = malloc(sizeof(int) * len);
    i = 0;
    while (i < len)
    {
		if ((to - from) < 0)
			*(range + i) = from - i;
		else
			*(range + i) = from + i;
        i++;
    }
    return (range);
}