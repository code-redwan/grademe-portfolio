#ifndef MINI_PRINTF_H
# define MINI_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

int	    mini_printf(const char *format, ...);
ssize_t gm_check_format(va_list args, char c);
ssize_t gm_putchar(const char c);
ssize_t	gm_putstr(const char *str);
ssize_t gm_putnbr(int nbr);
ssize_t gm_putunbr(unsigned int unbr);
ssize_t gm_address(uintptr_t address, int uppercase);
ssize_t	gm_pointer_address(uintptr_t address);

#endif