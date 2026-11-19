// Return 1 if n is a prime number, 0 otherwise.
// n is between -1000 and 100000.
int	is_prime(int n)
{
	int	i;

	if (n <= 1)
		return (0);
	i = 2;
	if (n == 2)
		return (1);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
