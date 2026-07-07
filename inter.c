#include <unistd.h>
#include <string.h>

void ft_inter(char *s1, char *s2)
{
    char *start = s1, *ptr = s1;

    while (*s1)
    {
        ptr = start;
        // 1. Scan s1 from the start up to our current position.
        while (s1 > ptr && *ptr != *s1)
            ptr++;

        // 2. If p == s1, it's unique so far.
        // 3. If ft_contains returns 1, it exists in s2. Print it.
        if (ptr == s1 && strchr(s2, *s1))
            write(1, s1, 1);

        s1++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
        if (argc != 3)
                write(1, "\n", 1);
        else
        {
                char *s1 = *++argv;
                char *s2 = *++argv;
                ft_inter(s1, s2);
        }
        return 0;
}
