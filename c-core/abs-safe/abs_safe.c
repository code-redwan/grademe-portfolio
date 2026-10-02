// Return the absolute value of n as a long.
// Widen to long before negating, never after.
long	abs_safe(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		return (nb * (-1));
	return (nb);
}