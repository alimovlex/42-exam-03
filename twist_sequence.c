#include <stdio.h>
#include <stdlib.h>

void ft_twist_sequence(char **argv)
{
    // Extract length and k from arguments using base pointer offsets
    int len = atoi(*(argv + 1)), k = atoi(*(argv + 2));
    // Handle empty array edge case safely
    if (len == 0)
    {
        printf("\n");
        return;
    }
    // Normalize k in case k is larger than the array length
    k = k % len;
    // elements pointer points to the start of the array values in argv
    char **elements = argv + 3;
    char **ptr;
    // Step 1: Print the last 'k' elements (they rotate to the front)
    ptr = elements + (len - k);
    while (ptr < elements + len)
    {
        printf("%s ", *ptr);
        ptr++;
    }
    // Step 2: Print the remaining head elements
    ptr = elements;
    while (ptr < elements + (len - k))
    {
        printf("%s ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("\n");
        return (0);
    }
    else
        ft_twist_sequence(argv);

    return (0);
}
