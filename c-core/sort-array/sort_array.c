void sort_array(int *tab, unsigned int size)
{
    unsigned int     i;
    int     tmp;

    i = 0;
    if (size == 0)
        return ;
    while (i < (size - 1))
    {
        if (tab[i] > tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}
