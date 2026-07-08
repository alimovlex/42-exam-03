#include <stdio.h>
#include <ctype.h>

void ft_anagram(char *s1, char *s2)
{
    int counts[26] = {0};
    int *c_ptr;

    // Process first string using standard ctype functions
    while (*s1)
    {
        if (isalpha(*s1))
        {
            char lower = tolower(*s1);
            *(counts + (lower - 'a')) += 1; // Pure pointer arithmetic
        }
        s1++;
    }

    // Process second string using standard ctype functions
    while (*s2)
    {
        if (isalpha(*s2))
        {
            char lower = tolower(*s2);
            *(counts + (lower - 'a')) -= 1; // Pure pointer arithmetic
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
