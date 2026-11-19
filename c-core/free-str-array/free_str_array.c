#include <stdlib.h>
#include <stddef.h>

// Frees the NULL-terminated arr and every string it holds.
// Returns how many strings were freed.
size_t	free_str_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (i);
}
