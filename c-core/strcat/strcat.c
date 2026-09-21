static int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*gm_strcat(char *dst, const char *src)
{
	int		len;
	int		i;

	len = ft_strlen(dst);
	i = 0;
	while (*(src + i))
	{
		*(dst + len) = *(src + i);
		len++;
		i++;
	}
	*(dst + len) = '\0'; 
	return (dst);
}