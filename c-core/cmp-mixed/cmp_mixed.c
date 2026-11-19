// Compare the numeric values of a and b.
// Return -1 if a is smaller, 0 if both mean the same number, 1 if a is larger.
int	cmp_mixed(int a, unsigned int b)
{
	if (a < 0)
		return (-1);
	if ((unsigned int)a < b)
		return (-1);
	if ((unsigned int)a > b)
		return (1);
	return (0);
}
