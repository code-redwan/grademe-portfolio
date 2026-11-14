#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#define HEX_LOWER "0123456789abcdef"

static	ssize_t gm_putchar(const char c)
{
	return (write(1, &c, 1));
}

static	ssize_t	gm_putstr(const char *str)
{
	size_t	bytes;

    if (!str)
    {
        if (gm_putstr("(null)") < 0)
			return (-1);
		return (6);
    }
    bytes = 0;
	while (*(str + bytes))
	{
		if (gm_putchar(*(str + bytes)) < 0)
			return (-1);
		bytes++;
	}
	return (bytes);
}

static	ssize_t gm_putnbr(int nbr)
{
    long    nb;
    size_t  bytes;
    ssize_t rec;
    char digit;

    nb = nbr;
    bytes = 0;
    if (nb < 0)
    {
        if (gm_putchar('-') < 0)
            return (-1);
        bytes += 1;
        nb = nb * (-1);
    }
    if (nb >= 10)
    {
        rec = gm_putnbr(nb / 10);
        if (rec < 0)
            return (-1);
        bytes += rec;
    }
    digit = (nb % 10) + '0';
    if(gm_putchar(digit) < 0)
        return (-1);
    bytes += 1;
    return (bytes);
}

static	ssize_t gm_puthex(uintptr_t address)
{
    size_t	bytes;
    ssize_t rec;
    char*   base;

    bytes = 0;
    base = HEX_LOWER;
    if (address >= 16)
    {
        rec = gm_puthex(address / 16);
        if (rec < 0)
            return (-1);
        bytes += rec;
    }
    if (gm_putchar(base[address % 16]) < 0)
        return (-1);
    bytes += 1;
    return (bytes);
}

ssize_t gm_check_format(va_list args, char c)
{
	ssize_t	bytes;

	bytes = 1;
	if (c == 'c')
		bytes = gm_putchar(va_arg(args, int));
	else if (c == 's')
		bytes = gm_putstr(va_arg(args, char *));
	else if (c == 'd')
		bytes = gm_putnbr(va_arg(args, int));
	else if (c == 'x')
		bytes = gm_puthex(va_arg(args, unsigned int));
	else if (c == '%')
		bytes = gm_putchar('%');
	else
	{
		bytes = 0;
		if (gm_putchar('%') < 0)
			return (-1);
		bytes++;
		if (gm_putchar(c) < 0)
			return (-1);
		bytes++;
	}
	if (bytes < 0)
		return (-1);
	return (bytes);
}

int	mini_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	bytes;
	ssize_t	return_check_format;

	va_start(args, format);
	bytes = 0;
	while (*format)
	{
    	if (*format == '%' && *(format + 1))
    	{
      	  	return_check_format = gm_check_format(args, *(format + 1));
        	if (return_check_format < 0)
        	{
          		va_end(args);
         	   return (-1);
      	  	}
        	bytes += return_check_format;
        	format += 2;
    	}
   	 	else
   		{
        	if (*format == '%')
        	{
            	va_end(args);
            	return (-1);
        	}
        	if (gm_putchar(*format) < 0)
       	 	{
				va_end(args);
				return (-1);
        	}
			bytes++;
			format++;
		}
	}
	va_end(args);
	return (bytes);
}