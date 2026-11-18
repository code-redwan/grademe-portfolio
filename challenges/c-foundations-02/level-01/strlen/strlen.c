#include <stddef.h>

size_t	gm_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}
