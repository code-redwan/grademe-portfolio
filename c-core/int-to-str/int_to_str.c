#include <stdlib.h>
#include <limits.h>

static int	gm_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

static char	*gm_strdup(const char *src)
{
	int		index;
	int		len;
	char	*dest;

	len = gm_strlen(src);
	dest = malloc((sizeof(char) * len) + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (*(src + index))
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest);
}

static int	gm_intlen(int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*int_to_str(int n)
{
	int		len;
	int		sign;
	char	*str;

	if (n == INT_MIN)
		return (gm_strdup("-2147483648"));
	if (n == 0)
		return (gm_strdup("0"));
	len = 0;
	sign = 0;
	if (n < 0)
	{
		len = 1;
		n = n * (-1);
		sign = -1;
	}
	len = len + gm_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	while (0 <= len)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}