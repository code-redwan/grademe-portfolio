// digit_sum(n) is the last digit of n plus digit_sum(n / 10).
// The sign is dropped, and n itself is never negated: -INT_MIN does not fit.
int	digit_sum(int n)
{
	int		sum;
	long	number;

	sum = 0;
	number = n;
	if (number < 0)
		number = number * (-1);
	while (number != 0)
	{
		sum = sum + (number % 10);
		number = number / 10;
	}
	return (sum);
}