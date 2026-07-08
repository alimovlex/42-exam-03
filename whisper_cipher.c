#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void ft_whisper_cipher(char *str, int number)
{
    // Normalize shift bounds to fit perfectly within the 26-letter alphabet
    number %= 26;
    if (number < 0)
        number += 26;

    // Process the string using a raw moving pointer
    while (*str)
    {
        if (isupper(*str))
            // Shift within 'A'-'Z' bounds
            printf("%c", 'A' + (*str - 'A' + number) % 26);
        else if (islower(*str))
            // Shift within 'a'-'z' bounds
            printf("%c", 'a' + (*str - 'a' + number) % 26);
        else
            // Non-alphabetic characters pass through exactly as-is
            printf("%c", *str);
        str++; // Advance raw pointer step
    }
}

int main(int argc, char **argv)
{
    // If we don't have enough arguments, return early
    if (argc < 3)
        return (0);
    else
    {
        char *str = *++argv;
        int number = atoi(*++argv);
        ft_whisper_cipher(str, number);
    }
    return (0);
}
