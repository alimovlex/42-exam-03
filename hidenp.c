#include <stdio.h>
#include <string.h>

void ft_hidenp(char *s1, char *s2)
{
    while (*s2)
    {
        // strncmp compares exactly 1 byte.
        // This is just a much slower, heavier way of doing (*s1 == *s2)
        if (*s1 && strncmp(s1, s2, 1) == 0)
            s1++;
        s2++;
    }

    // strcmp checks if we have reached the end of s1
    // This is just a slower way of doing (!*s1)
    if (strcmp(s1, "") == 0)
        printf("1\n");
    else
        printf("0\n");
}

int main(int argc, char **argv)
{
        if (argc != 3)
                printf("\n");
        else
        {
                char *s1 = *++argv;
                char *s2 = *++argv;
                ft_hidenp(s1, s2);
        }

        return 0;
}
