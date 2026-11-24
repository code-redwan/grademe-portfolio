#include <stddef.h>

size_t	gm_strcspn(const char *s, const char *reject)
{
	int	i;
	int	x_i;

	i = 0;
	while (*(s + i))
	{
		x_i = 0;
		while (*(reject + x_i))
		{
			if (*(s + i) == *(reject + x_i))
			{
				return (i);
			}
			x_i++;
		}
		i++;
	}
	return (i);
}
