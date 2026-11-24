#include <stddef.h>

char	*gm_strstr(const char *haystack, const char *needle)
{
	int	index;
	int	x_index;

	if (*needle == '\0')
		return ((char* )haystack);
	index = 0;
	while (*(haystack + index))
	{
		x_index = 0;
		while (*(needle + x_index) && *(haystack + (index + x_index)) == *(needle + x_index))
			x_index++;
		if (*(needle + x_index) == '\0')
			return ((char* )haystack + index);
		index++;
	}
	return (NULL);
}
