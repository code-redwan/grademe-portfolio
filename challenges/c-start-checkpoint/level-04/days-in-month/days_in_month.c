// month runs from 1 for January to 12 for December, and only February
// looks at year. A number outside that range has no length to report.
static int	gm_is_leap(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return (1);
	return (0);
}

int	days_in_month(int year, int month)
{
	int	leap_year;

	if (month < 1 || month > 12)
		return (-1);
	if (month == 2)
	{
		leap_year = gm_is_leap(year);
		if (leap_year == 1)
			return (29);
		else
			return (28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	else
		return (31);
}
