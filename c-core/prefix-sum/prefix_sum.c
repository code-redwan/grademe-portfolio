#include <stddef.h>

// out[i] holds the sum of a[0] through a[i], and a stays read-only.
// The running total is a long because it can outgrow an int.
void	prefix_sum(const int *a, size_t n, long *out)
{
	long	sum;

	sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum = a[i] + sum;
		out[i] = sum;
	}
}
