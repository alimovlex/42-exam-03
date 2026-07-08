#include <stdio.h>
#include <stdlib.h>

void ft_mirror_matrix(char **argv)
{
    int rows = atoi(*(argv + 1));
    int cols = atoi(*(argv + 2));
    int r = 0;

    char **curr_row_start = argv + 3;

    while (r < rows)
    {
        char **end = curr_row_start + cols - 1;
        while (end >= curr_row_start)
        {
            printf("%s", *end);
            if (end > curr_row_start)
                printf(" ");
            end--;
        }
        printf("\n");
        curr_row_start += cols; // Shift base pointer to the next row sequence
        r++;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return (0);
    else
        ft_mirror_matrix(argv);
    return (0);
}
