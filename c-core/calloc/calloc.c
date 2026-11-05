#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void	*gm_calloc(size_t nmemb, size_t size)
{
	void *calloc;
	size_t	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
    	return (NULL);
	calloc = malloc(nmemb * size);
	if (!calloc)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)calloc)[i] = 0;
		i++;
	}
	return (calloc);
}
