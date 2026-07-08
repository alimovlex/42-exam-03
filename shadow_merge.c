#include <stdio.h>
#include <stdlib.h>

void ft_shadow_merge(char **argv)
{
    // Move past the binary name execution argument
    argv++;

    // Extract lengths using pointer steps
    int len1 = atoi(*argv);
    argv++;
    int len2 = atoi(*argv);
    argv++;

    // Set up our list boundaries using raw pointer arithmetic
    char **ptr1 = argv;
    char **end1 = argv + len1;
    char **ptr2 = end1;
    char **end2 = end1 + len2;

    // Classic merge sort comparison stage using raw pointers
    while (ptr1 < end1 && ptr2 < end2)
    {
        if (atoi(*ptr1) <= atoi(*ptr2))
        {
            printf("%s ", *ptr1);
            ptr1++;
        }
        else
        {
            printf("%s ", *ptr2);
            ptr2++;
        }
    }

    // Clean up remaining elements from list1
    while (ptr1 < end1)
    {
        printf("%s ", *ptr1);
        ptr1++;
    }

    // Clean up remaining elements from list2
    while (ptr2 < end2)
    {
        printf("%s ", *ptr2);
        ptr2++;
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
        ft_shadow_merge(argv);
}
