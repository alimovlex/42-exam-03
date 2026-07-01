#!/usr/bin/env python3
import subprocess
import os

def cryptic_sorter(strings: list[str]) -> list[str]:
    # Edge case: If the input list is empty, return empty immediately
    if not strings:
        return []

    # Embedded C Program with custom multi-criteria sorting
    c_file_content = r"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *str;
    int original_index;
} StringElem;

// Helper function to count vowels case-insensitively
int count_vowels(const char *s) {
    int count = 0;
    while (*s) {
        char c = tolower((unsigned char)*s);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        s++;
    }
    return count;
}

// Comparator function for qsort
int compare_elems(const void *a, const void *b) {
    const StringElem *ea = (const StringElem *)a;
    const StringElem *eb = (const StringElem *)b;
    
    // 1. Primary sort: By string length (shortest first)
    size_t len_a = strlen(ea->str);
    size_t len_b = strlen(eb->str);
    if (len_a != len_b) {
        return (len_a < len_b) ? -1 : 1;
    }
    
    // 2. Secondary sort: ASCII order, except letters are compared case-insensitively
    size_t i = 0;
    while (ea->str[i] && eb->str[i]) {
        char ca = tolower((unsigned char)ea->str[i]);
        char cb = tolower((unsigned char)eb->str[i]);
        if (ca != cb) {
            return (ca < cb) ? -1 : 1;
        }
        i++;
    }
    
    // 3. Tertiary sort: By number of vowels (ascending)
    int v_a = count_vowels(ea->str);
    int v_b = count_vowels(eb->str);
    if (v_a != v_b) {
        return v_a - v_b;
    }
    
    // Case-insensitivity tie-breaker fallback: Standard ASCII order
    // This ensures "AAA" comes before "aaa" as requested in Example 2
    int ascii_cmp = strcmp(ea->str, eb->str);
    if (ascii_cmp != 0) {
        return ascii_cmp;
    }
    
    // 4. Stable sort fallback: Equal strings preserve their original input index order
    return ea->original_index - eb->original_index;
}

int main(int argc, char **argv) {
    if (argc < 2) return 0;
    
    int num_strings = argc - 1;
    StringElem *elems = malloc(num_strings * sizeof(StringElem));
    
    for (int i = 0; i < num_strings; i++) {
        elems[i].str = argv[i + 1];
        elems[i].original_index = i;
    }
    
    // Sort array using custom comparator
    qsort(elems, num_strings, sizeof(StringElem), compare_elems);
    
    // Print each sorted string followed by a newline
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", elems[i].str);
    }
    
    free(elems);
    return 0;
}
"""

    # 1. Write out the temporary C file
    with open("temp.c", "w") as f:
        f.write(c_file_content)
        
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", "temp.c", "-o", "sorter_bin"], capture_output=True, text=True)
    
    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(["./sorter_bin"] + strings, capture_output=True, text=True)
    
    # 4. Clean up output strings safely by splitting strictly on newlines
    output_lines = result.stdout.split('\n')
    if output_lines and output_lines[-1] == '':
        output_lines.pop()  # Removes trailing blank line caused by final \n
        
    return output_lines