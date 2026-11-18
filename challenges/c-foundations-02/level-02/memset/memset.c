#include <stddef.h>

void *gm_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(str + i) = (char)c;
		i++;
	}
	return ((void*)str);
}
