#include <cctype>
#include <iostream>

void ft_string_sculptor(std::string &str)
{
    bool is_lower = true;
    std::string::const_iterator itr;
    // Traversing via std::string::const_iterator
    for (itr = str.begin(); itr != str.end(); ++itr)
    {
        unsigned char uc = static_cast<unsigned char>(*itr);
        if (uc == ' ')
        {
            std::cout << *itr;
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
            std::cout << *itr;
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
    }
    return 0;
}
