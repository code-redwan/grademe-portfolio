#include <stddef.h>

// Flip the order of the first n elements of a, in place.
// Nothing past that prefix moves, and n == 0 changes nothing.
void	reverse_int(int *a, size_t n)
{
	size_t	index;
	int	tmp;

	index = 0;
	while (index < (n / 2))
	{
		tmp = *(a + index);
		*(a + index) = *(a + (n - index - 1));
		*(a + (n - index - 1)) = tmp;
		index++;
	}
}
