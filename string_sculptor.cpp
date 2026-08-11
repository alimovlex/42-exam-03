#include <cctype>
#include <iostream>
#include <string>

void ft_string_sculptor(const std::string &str)
{
    bool is_lower = true;
    // C++11 range-based for loop
    for (char ch : str)
    {
        unsigned char uc = static_cast<unsigned char>(ch);
        if (uc == ' ')
        {
            std::cout << ch;
            is_lower = true;
        }
        else if (std::isalpha(uc))
        {
            if (is_lower)
                std::cout << static_cast<char>(std::tolower(uc));
            else
                std::cout << static_cast<char>(std::toupper(uc));

            is_lower = !is_lower;
        }
        else
            std::cout << ch;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    else
    {
        std::string str = *++argv;
        ft_string_sculptor(str);
        return 0;
    }
}
