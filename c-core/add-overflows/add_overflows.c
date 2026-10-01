#include <limits.h>
// Return 1 when a + b would fall outside the range of an int, 0 when it fits.
// Decide by comparing a against a bound. Computing a + b is never allowed.
int	add_overflows(int a, int b)
{
	long 	result;

	result = (long)a + b;
	if (result >= INT_MIN && result <= INT_MAX)
		return (0);
	return (1);
}
