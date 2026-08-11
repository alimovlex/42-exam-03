#include <iostream>
#include <string>
#include <vector>

void ft_shadow_merge(std::vector<std::string> &args)
{
    std::vector<std::string>::const_iterator itr;
    itr = args.cbegin();
    int len1 = std::stoi(*itr);
    itr++;
    int len2 = std::stoi(*itr);
    itr++;
    // Set up iterator boundaries matching C pointer arithmetic
    std::vector<std::string>::const_iterator ptr1 = itr;
    std::vector<std::string>::const_iterator end1 = ptr1 + len1;
    std::vector<std::string>::const_iterator ptr2 = end1;
    std::vector<std::string>::const_iterator end2 = end1 + len2;

    // Merge comparison stage
    while (ptr1 < end1 && ptr2 < end2)
    {
        if (std::stoi(*ptr1) <= std::stoi(*ptr2))
        {
            std::cout << *ptr1 << " ";
            ++ptr1;
        }
        else
        {
            std::cout << *ptr2 << " ";
            ++ptr2;
        }
    }

    // Print remaining elements from list 1
    while (ptr1 < end1)
    {
        std::cout << *ptr1 << " ";
        ++ptr1;
    }

    // Print remaining elements from list 2
    while (ptr2 < end2)
    {
        std::cout << *ptr2 << " ";
        ++ptr2;
    }

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 3)
        std::cout << std::endl;
    else
    {
        std::vector<std::string> args;
        while(*++argv)
            args.push_back(*argv);
        ft_shadow_merge(args);
    }
    return 0;
}
