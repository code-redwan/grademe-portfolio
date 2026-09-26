#include <stdlib.h>
#include <stddef.h>

// str_join returns a fresh string holding the n strings of parts, separated by
// sep. The caller frees it.
static	int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

static	int	ft_strslen(char **strs, size_t n)
{
	size_t	i;
	int	len;

	i = 0;
	len = 0;
	while (i < n)
	{
		len = len + ft_strlen(*(strs + i));
		i++;
	}
	return (len);
}

char	*str_join(char **parts, size_t n, char sep)
{
	char	*string;
	int		total;
	size_t		i;
	int		index;
	int		current;

	if (n == 0)
	{
		string = malloc(sizeof(char) * 1);
		if (!string)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	total = ft_strslen(parts, n) + (n - 1) + 1;
	string = malloc(sizeof(char) * total);
	if (!string)
		return (NULL);
	i = 0;
	current = 0;
	while (i < n)
	{
		index = 0;
		while (parts[i][index])
		{
			string[current] = parts[i][index];
			index++;
			current++;
		}
		if (i != (n - 1))
		{
			string[current] = sep;
			current++;
		}
		i++;
	}
	string[current] = '\0';
	return (string);
}
