#include <stdio.h>

void ft_string_permutation_checker(char **argv)
{
    // Cast to unsigned char to prevent negative array indexing with extended ASCII
    unsigned char *p1 = (unsigned char *)argv[1];
    unsigned char *p2 = (unsigned char *)argv[2];
    int counts[256] = {0};
    int *c_ptr;

    // Increment bucket for every character found in string 1
    while (*p1)
    {
        *(counts + *p1) += 1;
        p1++;
    }

    // Decrement bucket for every character found in string 2
    while (*p2)
    {
        *(counts + *p2) -= 1;
        p2++;
    }

    // Verify all ASCII frequency buckets balanced out to perfectly 0
    c_ptr = counts;
    while (c_ptr < counts + 256)
    {
        if (*c_ptr != 0)
        {
            printf("0\n");
            return;
        }
        c_ptr++;
    }

    printf("1\n");
}

int main(int argc, char **argv)
{
    // If we don't have enough arguments, it means Python passed empty boundaries
    if (argc < 3)
    {
        printf("1\\n");
        return (0);
    }
    else
    {
        ft_string_permutation_checker(argv);
        return 0;
    }
}
