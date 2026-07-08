#include <stdio.h>
#include <ctype.h>

void ft_string_sculptor(char *str)
{
    int is_lower = 1;

    while (*str)
    {
        if (*str == ' ')
        {
            printf("%c", *str);
            is_lower = 1;
        }
        else if (isalpha(*str))
        {
            if (is_lower)
                printf("%c", tolower(*str));
            else
                printf("%c", toupper(*str));
            is_lower = !is_lower;
        }
        else
                printf("%c", *str);
            str++;
    }
}

int main(int argc, char **argv)
{
    // If no argument is passed at all, safeguard execution
    if (argc != 2)
        return 0;
    else
     ft_string_sculptor(*++argv);
    return (0);
}
