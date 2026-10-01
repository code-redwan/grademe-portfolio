#include <limits.h>
#include <stdio.h>
// Return 1 when a + b would fall outside the range of an int, 0 when it fits.
// Decide by comparing a against a bound. Computing a + b is never allowed.
int	add_overflows(int a, int b)
{
	long 	big_a;

	big_a = a;
	big_a = big_a + b;
	if (big_a >= INT_MIN && big_a <= INT_MAX)
		return (0);
	return (1);
}