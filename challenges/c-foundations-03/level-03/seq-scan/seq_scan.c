#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char a;
    char b;

    if (argc != 3)
    {
        write(1, "wrong number of arguments\n", 26);
        return (0);
    }
    i = 0;
    j = 0;
    while (argv[1][i] && argv[2][j])
    {
        a = argv[1][i];
        b = argv[2][j];
        if (a >= 'A' && a <= 'Z')
            a += 32;
        if (b >= 'A' && b <= 'Z')
            b += 32;
        if (a == b)
            i++;
        j++;
    }
    if (argv[1][i] == '\0')
        write(1, argv[1], i);
    write(1, "\n", 1);
    return (0);
}