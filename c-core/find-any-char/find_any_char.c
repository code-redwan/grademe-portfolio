#include <stddef.h>

char *find_any_char(const char *text, const char *needles)
{
	const char *start;

	while (*text)
	{
		start = needles;
		while (*start)
		{
			if (*text == *start)
				return ((char *)text);
			start++;
		}
		text++;
	}
	return (NULL);
}
