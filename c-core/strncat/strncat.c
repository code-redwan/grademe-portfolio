#include <stddef.h>

static int	gm_strlen(const char *str)
{
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*gm_strncat(char *dest, const char *src, size_t n)
{
	int		len;
	size_t	i;

	len = gm_strlen(dest);
	i = 0;
	while (*src && i < n)
	{
		*(dest + len++) = *src++;
		i++;
	}
	*(dest + len) = '\0';
	return (dest);
}