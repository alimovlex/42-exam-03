#include <iostream>

void ft_inter(const std::string &s1, const std::string &s2)
{
    std::size_t pos = 0;
    for (char ch : s1)
    {
        // 1. s1.find(ch) == i  -> True ONLY if 'ch' is appearing for the very first time in s1
        // 2. s2.find(ch) != npos -> True if 'ch' exists in s2
        if (s1.find(ch) == pos && s2.find(ch) != std::string::npos)
            std::cout << ch;
        pos++;
    }
    std::cout << std::endl;
    /*
    std::string::const_iterator it_s1 = s1.cbegin();
    std::size_t pos = 0; // Tracks our search offset in s2
    while (it_s1 != s1.cend())
    {
        // 1. Check if *it1 appeared earlier in s1 (up to current iterator position)
        std::string::const_iterator scan_it_s1 = s1.cbegin();
        while (scan_it_s1 != it_s1 && *scan_it_s1 != *it_s1)
            scan_it_s1++;
        if (scan_it_s1 == it_s1 && s2.find(*it_s1) != std::string::npos)
            std::cout << *it_s1;
        it_s1++;
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
        ft_inter(s1, s2);
    }
    return 0;
}
