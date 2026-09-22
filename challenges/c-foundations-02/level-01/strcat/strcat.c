static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = ft_strlen(dest);
	i = 0;
	while (*(src + i))
	{
		*(dest + len) = *(src + i);
		len++;
		i++;
	}
	*(dest + len) = '\0';
	return (dest);
}
