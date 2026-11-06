// month runs from 1 for January to 12 for December, and only February
// looks at year. A number outside that range has no length to report.
static int	is_leap(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
		return (1);
	return (0);
}
int	days_in_month(int year, int month)
{
	int	leap;

	if (month < 1 || month > 12)
		return (-1);
	if (month == 2)
	{
		leap = is_leap(year);
		if (leap == 1)
			return (29);
		return (28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	else
		return (31);
}
