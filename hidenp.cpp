#include <iostream>

void ft_hidenp(const std::string &s1, const std::string &s2)
{
    std::string::const_iterator it_s1 = s1.cbegin();
    std::size_t pos = 0; // Search starting index in s2

    while (it_s1 != s1.cend())
    {
        // Find *it1 in s2, starting search at index 'pos'
        pos = s2.find(*it_s1, pos);
        // If the character is not found in the rest of s2, fail early
        if (pos == std::string::npos)
                break;
        pos++; // Move search offset past the matched character
        it_s1++; // Move to the next character in s1
    }

    // Check if s1's iterator reached the end
    if (it_s1 == s1.cend())
        std::cout << "1" << std::endl;
    else
        std::cout << "0" << std::endl;

    /*  Range-based for loop (for-each character in s2)
    //std::string::const_iterator it_s2 = s2.cbegin();
    for (char ch : s2)
        if (it_s1 != s1.cend() && ch == *it_s1)
            it_s1++; // Move iterator to the next character in s1

    // Loop while there are still characters to process in both s2 and s1
    while (it_s2 != s2.cend() && it_s1 != s1.cend())
    {
        if (*it_s1 == *it_s2)
            it_s1++; // Advance s1 iterator on match
        it_s2++; // Always advance s2 iterator
    }
    */


}

int main(int argc, char **argv)
{
    if (argc != 3)
        std::cout << std::endl;
    else
    {
        std::string s1 = *++argv;
        std::string s2 = *++argv;
        ft_hidenp(s1, s2);
    }
    return 0;
}
