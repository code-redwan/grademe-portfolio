#include <stddef.h>

char	*gm_strrchr(const char *s, int c)
{
	char	*occurrence;
	
	occurrence = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			occurrence = (char*)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char*)s);
	return ((char*)occurrence);
}