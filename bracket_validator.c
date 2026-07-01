#include <stdlib.h>

int is_open(char c) 
{
    return c == '(' || c == '[' || c == '{';
}

int matches(char open, char close) 
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        /* Empty string is valid */
        return 0;
    }

    char *s = argv[1];
    int len = 0;
    while (s[len] != '\0') 
      len++;

    char *stack = (char *)malloc(len);
    if (!stack)
        return 1;  /* treat alloc failure as invalid */

    int top = -1;

    for (int i = 0; i < len; i++) 
    {
        char c = s[i];

        if (is_open(c)) 
            stack[++top] = c;
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (top < 0) 
            {
                free(stack);
                return 1;  /* closing with no opening */
            }
            char open = stack[top--];
            if (!matches(open, c)) 
            {
                free(stack);
                return 1;  /* wrong kind of closing */
            }
        }
    }

    int result = 0;
    if (top >= 0)
        /* still have unmatched opening brackets */
        result = 1;
    free(stack);
    return result;  /* 0 = valid, 1 = invalid */
}