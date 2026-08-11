#include <iostream>
#include <array>
#include <vector>

void ft_string_permutation_checker(const std::vector<std::string> &args)
{
    // Access the first two string references via vector iterator
    std::vector<std::string>::const_iterator args_itr;
    args_itr = args.cbegin();
    const std::string s1 = *args_itr;
    args_itr++;
    const std::string s2 = *args_itr;
    std::array<int, 256> counts{};

    // Iterate through string 1 using string::const_iterator
    for (auto itr = s1.begin(); itr != s1.end(); ++itr)
    {
        // Cast to unsigned char to prevent negative offset on extended ASCII
        unsigned char c = static_cast<unsigned char>(*itr);
        // Use iterator arithmetic on the array iterator
        *(counts.begin() + c) += 1;
    }

    // Iterate through string 2 using string::const_iterator
    for (auto itr = s2.begin(); itr != s2.end(); ++itr)
    {
        unsigned char c = static_cast<unsigned char>(*itr);
        *(counts.begin() + c) -= 1;
    }

    // Check buckets using array::const_iterator
    for (auto itr = counts.begin(); itr != counts.end(); ++itr)
    {
        if (*itr != 0)
        {
            std::cout << "0" << std::endl;
            return;
        }
    }

    std::cout << "1" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 3)
        std::cout << "1" << std::endl;
    else
    {
        std::vector<std::string> args;
        while(*++argv)
            args.push_back(*argv);
        ft_string_permutation_checker(args);
    }
    return 0;
}
