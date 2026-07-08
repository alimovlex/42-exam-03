#include <stdio.h>
#include <ctype.h>

void ft_string_sculptor(char *str)
{
    int upper_state = 0; // 0 = lowercase turn, 1 = uppercase turn

    while (*str)
    {
        if (*str == ' ')
        {
            upper_state = 0; // Spaces reset the alternation sequence
            printf("%c", *str);
        }
        else
        {
            // Normalize to lowercase using your 5th-bit OR trick
            char lower = *str | 32;

            // Check if character is alphabetic
            if (isalpha(lower))
            {
                if (upper_state == 0)
                {
                    printf("%c", lower); // Force lowercase
                    upper_state = 1;     // Flip state to expect uppercase next
                }
                else
                {
                    // Force uppercase using bitwise AND against 223 (11011111 in binary)
                    //printf("%c", *str & 223);
                    printf("%c", *str ^ 32);
                    upper_state = 0;     // Flip state to expect lowercase next
                }
            }
            else
                // Non-alphabetic characters are printed as-is without altering state
                printf("%c", *str);
        }
        str++; // Advance raw pointer
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
