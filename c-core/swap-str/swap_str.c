#include <stddef.h>

void    swap_str(char **a, char **b)
{
    char *temp;

    if (a == NULL || b == NULL)
        return;
    temp = *a;
    *a = *b;
    *b = temp;
}