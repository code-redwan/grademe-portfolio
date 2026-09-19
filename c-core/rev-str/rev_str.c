int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char *rev_str(char *str)
{
	int		len;
	int		i;
	int		tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < (len / 2))
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}