#include <stdio.h>

void ft_anagram(char *s1, char *s2)
{
    int counts[26] = {0};
    int *c_ptr;

    // Process first string using bitwise lowercase normalization
    while (*s1)
    {
        char lower = *s1 | 32;
        if (lower >= 'a' && lower <= 'z')
        {
            *(counts + (lower - 'a')) += 1;
        }
        s1++;
    }

    // Process second string using bitwise lowercase normalization
    while (*s2)
    {
        char lower = *s2 | 32;
        if (lower >= 'a' && lower <= 'z')
        {
            *(counts + (lower - 'a')) -= 1;
        }
        s2++;
    }

    // Verify all frequency buckets returned to 0
    c_ptr = counts;
    while (c_ptr < counts + 26)
    {
        if (*c_ptr != 0)
        {
            printf("0\n");
            return;
        }
        c_ptr++;
    }

    printf("1\n");
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("0\n");
        return (0);
    }
    else
    {
        char *s1 = *++argv;
        char *s2 = *++argv;
        ft_anagram(s1, s2);
    }
    return (0);
}
