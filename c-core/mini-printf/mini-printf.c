#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

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

static	ssize_t gm_putunbr(unsigned int unbr)
{
    size_t	bytes;
    ssize_t  rec;
    char    digit;

    bytes = 0;
    digit = 0;
    if (unbr >= 10)
    {
        rec = gm_putunbr(unbr / 10);
        if (rec < 0)
            return (-1);
        bytes += rec;
    }
    digit = (unbr % 10) + '0';
    if (gm_putchar(digit) < 0)
        return (-1);
    bytes += 1;
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

static	ssize_t gm_address(uintptr_t address, int uppercase)
{
    size_t	bytes;
    ssize_t rec;
    char*   base;

    bytes = 0;
    base = uppercase ? HEX_UPPER : HEX_LOWER;
    if (address >= 16)
    {
        rec = gm_address(address / 16, uppercase);
        if (rec < 0)
            return (-1);
        bytes += rec;
    }
    if (gm_putchar(base[address % 16]) < 0)
        return (-1);
    bytes += 1;
    return (bytes);
}

static	ssize_t	gm_pointer_address(uintptr_t address)
{
    ssize_t return_of_putstr;
    ssize_t return_of_puthexnb;
    
    if (!address)
        return (gm_putstr("(nil)"));
    if ((return_of_putstr = gm_putstr("0x")) < 0)
        return (-1);
    if ((return_of_puthexnb = gm_address(address, 0)) < 0)
        return (-1);
    return (return_of_putstr + return_of_puthexnb);
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
	else if (c == 'i')
		bytes = gm_putnbr(va_arg(args, int));
	else if (c == 'u')
		bytes = gm_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		bytes = gm_address(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		bytes = gm_address(va_arg(args, unsigned int), 1);
	else if (c == 'p')
		bytes = gm_pointer_address((uintptr_t)va_arg(args, void *));
	else if (c == '%')
		bytes = gm_putchar('%');
	else
	{
		bytes = gm_putchar('%');
		bytes += gm_putchar(c);
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
// #include <stdio.h>
// int main(void)
// {
// 	// printf("hi %s, %d+%d=%d %c %x%%\n", "dev", 2, 3, 5, '!', 255);
// 	int x = mini_printf("hi %s, %d+%d=%d %c %x%%\n", "dev", 2, 3, 5, '!', 255);
// }