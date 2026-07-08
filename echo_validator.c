#include <stdio.h>
#include <ctype.h>

int is_echo_palindrome(const char *s)
{
    char buf[1024];  /* local buffer declaration is fine, but we navigate it with pointers */
    char *b_ptr = buf;
    const char *s_ptr = s;

    /* 1. Build normalized buffer using a moving string pointer */
    while (*s_ptr)
    {
        if (isalpha((unsigned char)*s_ptr))
        {
            *b_ptr = (char)tolower((unsigned char)*s_ptr);
            b_ptr++;
        }
        s_ptr++;
    }
    /* 2. Empty after filtering? Check if the buffer pointer ever moved */
    if (b_ptr == buf)
        return 0;
    /* 3. Check palindrome using converging pointers */
    char *start = buf;
    char *end = b_ptr - 1; /* Point to the last valid character written */

    while (start < end)
    {
        if (*start != *end)
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("0\n");
        return 0;
    }
    else
    {
        int res = is_echo_palindrome(*++argv);
        printf("%d\n", res);
        return 0;
    }
}
