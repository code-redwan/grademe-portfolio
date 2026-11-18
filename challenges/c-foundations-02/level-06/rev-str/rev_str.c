#include <stddef.h>

static	unsigned gm_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*rev_str(char *str)
{
	int	len;
	int	i;
	char	tmp;

	len = gm_strlen(str) - 1;
	i = 0;
	while (i <= (len / 2))
	{
		tmp = *(str + i);
		*(str + i) = *(str + (len - i));
		*(str + (len - i)) = tmp;
		i++;
	}
	return (str);
}
