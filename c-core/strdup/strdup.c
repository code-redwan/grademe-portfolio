#include <stdlib.h>

int		ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while(*(str + len))
		len++;
	return (len);
}

char *strdup(const char *src)
{
	int		index;
	int		len;
	char	*dest;

	index = 0;
	len = ft_strlen(src);
	dest = malloc((sizeof(int) * len) + 1);
	if (!dest)
		return (NULL);
	while (*(src + index))
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest);
}
