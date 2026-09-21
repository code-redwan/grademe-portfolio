int max(int *tab, unsigned int len)
{
	int		max;
	unsigned int		i;

	max = tab[0];
	i = 1;
	if (!len)
		return (len);
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}