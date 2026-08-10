#include <cctype>
#include <iostream>

void ft_pattern_tracker(std::string &str)
{
    int count = 0;
    std::string::const_iterator itr;
    for (itr = str.begin(); itr != str.end(); ++itr)
    {
        if (std::isdigit(*itr) && *(itr + 1) == *itr + 1)
            count++;
    }
    std::cout << count << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "0" << std::endl;
        return 1;
    }
    else
    {
        std::string str = *++argv;
        ft_pattern_tracker(str);
        return 0;
    }
}
