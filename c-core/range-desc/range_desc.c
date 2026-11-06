#include <stdlib.h>

int *range_desc(int min, int max)
{
	int	*array;
	int	len;
	int	i;

	len = (max - min) + 1;
	array = malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(array + i) = max--;
		i++; 
	}
	return (array);
}