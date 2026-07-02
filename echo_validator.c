#include <stdio.h>
#include <ctype.h>

int is_echo_palindrome(const char *s) 
{
    char buf[1024];  /* enough for normal exam inputs */
    int n = 0;

    /* build normalized buffer: only letters, lowercased */
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (isalpha((unsigned char)s[i]))
            buf[n++] = (char)tolower((unsigned char)s[i]);
    }

    /* Empty after filtering? According to spec, "" returns False,
       so here we treat “no letters” as not palindrome. */
    if (n == 0)
        return 0;

    /* check palindrome with two indices */
    int i = 0;
    int j = n - 1;
    while (i < j) 
    {
        if (buf[i] != buf[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        /* No input: echo_validator("") should be False */
        printf("0\n");
        return 0;
    }

    int res = is_echo_palindrome(argv[1]);
    printf("%d\n", res);
    return 0;
}