#include <stddef.h>

// Return 1 when a[0..n - 1] never decreases, 0 at the first drop.
// Equal neighbours keep the answer 1. n of 0 or 1 is sorted by convention.
int	is_sorted(const int *a, size_t n)
{
	size_t	index;

	if (n == 0)
		return (1);
	index = 0;
	while (index < (n - 1))
	{
		if (a[index] > a[index + 1])
			return (0);
		index++;
	}
	return (1);
}
