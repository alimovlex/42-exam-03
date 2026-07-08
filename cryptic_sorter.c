#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char *str;
    int original_index;
} StringElem;

// Helper function to count vowels case-insensitively using a raw pointer
int count_vowels(const char *s)
{
    int count = 0;
    while (*s)
    {
        char c = tolower((unsigned char)*s);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
        s++;
    }
    return count;
}

// Comparator function for qsort using pure pointer navigation
int compare_elems(const void *a, const void *b)
{
    const StringElem *ea = (const StringElem *)a;
    const StringElem *eb = (const StringElem *)b;

    // 1. Primary sort: By string length (shortest first) using standard strlen
    size_t len_a = strlen(ea->str);
    size_t len_b = strlen(eb->str);

    if (len_a != len_b)
    {
        if (len_a < len_b)
            return -1;
        else
            return 1;
    }

    // 2. Secondary sort: ASCII order, except letters are compared case-insensitively
    char *p1 = ea->str;
    char *p2 = eb->str;
    while (*p1 && *p2)
    {
        char ca = tolower((unsigned char)*p1);
        char cb = tolower((unsigned char)*p2);
        if (ca != cb)
        {
            if (ca < cb)
                return -1;
            else
                return 1;
        }
        p1++;
        p2++;
    }

    // 3. Tertiary sort: By number of vowels (ascending)
    int v_a = count_vowels(ea->str);
    int v_b = count_vowels(eb->str);
    if (v_a != v_b)
        return v_a - v_b;

    // Case-insensitivity tie-breaker fallback: Standard ASCII order using strcmp
    int ascii_cmp = strcmp(ea->str, eb->str);
    if (ascii_cmp != 0)
        return ascii_cmp;

    // 4. Stable sort fallback: Equal strings preserve their original input index order
    return ea->original_index - eb->original_index;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;

    int num_strings = argc - 1;
    StringElem *elems = malloc(num_strings * sizeof(StringElem));
    if (!elems)
        return 1;

    // Populate structure array using moving target pointers
    StringElem *curr_elem = elems;
    char **curr_arg = argv + 1;
    int i = 0;

    while (i < num_strings)
    {
        curr_elem->str = *curr_arg;
        curr_elem->original_index = i;
        curr_elem++;
        curr_arg++;
        i++;
    }

    // Sort array using custom comparator
    qsort(elems, num_strings, sizeof(StringElem), compare_elems);

    // Print each sorted string using a tracking boundary pointer
    StringElem *print_ptr = elems;
    while (print_ptr < elems + num_strings)
    {
        printf("%s\n", print_ptr->str);
        print_ptr++;
    }

    free(elems);
    return 0;
}
