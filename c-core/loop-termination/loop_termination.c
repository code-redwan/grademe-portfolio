#include <stddef.h>

// One step replaces the running value with half of it, until the value is 0.
// This version compiles clean and is still wrong at run time.
size_t	count_steps(unsigned int start)
{
	unsigned int	value;
	size_t			steps;

	value = start;
	steps = 0;
	while (value != 0)
	{
		steps++;
		value = value / 2;
	}
	return (steps);
}
