#include <stdio.h>
#include <ctype.h>

void ft_pattern_tracker(char *str)
{
    int count = 0;

    // Strict while loop checking current and next character via pointers
    while (*str && *(str + 1))
    {
    // If current char is '0'-'8' and the next char is exactly 1 greater ASCII-wise
        if (isdigit(*str) && *(str + 1) == *str + 1)
            count++;
        str++; // Advance the pointer
    }

    printf("%d\n", count);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("0\n");
        return 1;
    }
    else
    {
        ft_pattern_tracker(*++argv);
        return (0);
    }
}
