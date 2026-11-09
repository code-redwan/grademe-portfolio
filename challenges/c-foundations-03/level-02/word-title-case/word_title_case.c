
#include <unistd.h>

static char *gm_capitalize(char *string)
{
    int i;
    int word;

    i = 0;
    word = 0;
    while (*(string + i))
    {
        if (*(string + i) >= 'A' && *(string + i) <= 'Z')
            *(string + i) = *(string + i) + 32;
        i++;
    }
    i = 0;
    while (*(string + i))
    {
        if (*(string + i) == ' ' || *(string + i) == '\t')
            word = 0;
        else
        {
            if (*(string + i) >= 'a' && *(string + i) <= 'z' && word == 0)
                *(string + i) = *(string + i) - 32;
            word = 1;
        }
        i++;
    }
    return (string);
}

static void gm_putstr(const char *string)
{
    while (*string)
    {
        write(1, string, 1);
        string++;
    }
}

int main(int argc, char **argv)
{
    int i;
    char *string;

    if (argc == 1)
    {
        write(1, "wrong number of arguments\n", 26);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        string = gm_capitalize(argv[i]);
        gm_putstr(string);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
