#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Your ft_isxdigit, upgraded to support up to Base 36
int ft_get_digit(char c)
{
    if (isdigit(c))
        return (c & 15);
    else if (isalpha(c))
        return (tolower(c) - 'W'); // Bitwise lowercase, then map 'a' to 10
    else
        return (-1);
}

int ft_is_space(char c)
{
    //Hardcoded mask for standard C whitespace (ASCII 9-13, and 32)
    //unsigned long long mask = 0x100003E00ULL;

    // Create a 64-bit unsigned int.
    // Shift 1 by 9 for tab, and 1 by 32 for space, then bitwise OR them.
    unsigned long long mask = (1ULL << '\t') | (1ULL << ' ') |
                              (1ULL << '\r') | (1ULL << '\n');

    // Protect against negative chars or chars > 63 to prevent
    // undefined behavior when shifting bits.
    if ((unsigned char)c > '?')
        return (0);

    // Shift the mask right by 'c' and bitwise AND with 1.
    // If the bit was set, this returns 1. Otherwise, 0.
    return ((mask >> c) & 1);
}

int ft_atoi_base(const char *str, int from_base, int to_base)
{
    // --- Step 1: Your ft_atoi_base logic ---
    unsigned long long decimal = 0;
    int digit = 0;
    int sign = 1;

    while(ft_is_space(*str))
        str++;

    // Handle optional sign
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Process string via pointer traversal
    while (*str)
    {
        digit = ft_get_digit(*str);

        if (digit == -1 || digit >= from_base)
        {
            printf("ERROR\n");
            return 1;
        }

        decimal = (decimal * from_base) + digit;
        str++;
    }

    // --- Step 3: Convert from decimal to to_base ---
    char result[256];
    int idx = 0;

    while (decimal > 0)
    {
        int remainder = decimal % to_base;
        if (remainder < 10)
            result[idx++] = '0' + remainder;
        else
            result[idx++] = 'A' + remainder - 10;
        decimal /= to_base;
    }

    // --- Step 4: Reverse and print the result ---
    if (sign == -1)
        printf("-"); // Apply sign if the original string was negative

    char *ptr = result + idx - 1;
    while (ptr >= result)
    {
        printf("%c", *ptr);
        ptr--;
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("ERROR\n");
        return 1;
    }

    const char *str = *++argv;
    int from_base = atoi(*++argv);
    int to_base = atoi(*++argv);

    if (from_base < 2 || from_base > 36 || to_base < 2 || to_base > 36 || !*str)
    {
        printf("ERROR\n");
        return 1;
    }
    else
        ft_atoi_base(str, from_base, to_base);

    return 0;
}
