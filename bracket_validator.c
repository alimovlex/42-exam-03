#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_open(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

int matches(char open, char close)
{
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

int ft_bracket_validator(char *str)
{
    // Allowed standard function used to allocate the precise memory needed
    size_t len = strlen(str);
    int result = 0;
    char *stack = (char *)malloc(len);
    // stk_ptr points to the next available empty slot in our stack
    char *stk_ptr = stack;
    char *ptr = str;

    while (*ptr)
    {
        char c = *ptr;
        if (is_open(c))
        {
            *stk_ptr = c;
            stk_ptr++; // Push onto stack
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            // If the stack pointer is still at the base address, it is empty
            if (stk_ptr == stack)
            {
                free(stack);
                return 1; /* Closing bracket with no opening bracket */
            }

            stk_ptr--; // Move back to the last occupied element (Pop)
            char open = *stk_ptr;

            if (!matches(open, c))
            {
                free(stack);
                return 1; /* Mismatched bracket type pair */
            }
        }
        ptr++;
    }
    // If the tracking pointer never returned back to the base address, elements remain
    if (stk_ptr > stack)
        result = 1; /* Unmatched opening brackets left behind */
    free(stack);
    return result; /* 0 = valid, 1 = invalid */
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    else
     return ft_bracket_validator(*++argv);

}
