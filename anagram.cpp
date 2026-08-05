#include <iostream>
#include <string>
#include <array>
#include <cctype>

void ft_anagram(const std::string &s1, const std::string &s2)
{
    // std::array zero-initializes all 26 elements
    std::array<int, 26> counts{};

    // Count character frequencies in the first string
    for (unsigned char c : s1)
        if (std::isalpha(c))
            counts[std::tolower(c) - 'a']++;

    // Decrement character frequencies for the second string
    for (unsigned char c : s2)
        if (std::isalpha(c))
            counts[std::tolower(c) - 'a']--;

    // Verify all frequency counts returned to 0
    for (int count : counts)
    {
        if (count != 0)
        {
            std::cout << "0" << std::endl;
            return;
        }
    }

    std::cout << "1" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 3)
        std::cout << "0" << std::endl;
    else
    {
        std::string s1 = *++argv;
        std::string s2 = *++argv;
        ft_anagram(s1, s2);
    }
    return 0;
}
