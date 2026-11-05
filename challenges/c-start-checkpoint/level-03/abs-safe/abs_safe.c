// Return the absolute value of n as a long.
// Every int is a valid n, INT_MIN included.
long	abs_safe(int n)
{
	long	safe_value;

	safe_value = n;
	if (safe_value < 0)
		return (safe_value * (-1));
	return (safe_value);
}
