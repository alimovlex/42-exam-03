#include <iostream>
#include <string>
#include <vector>

void ft_mirror_matrix(std::vector<std::string> &args)
{
    std::vector<std::string>::const_iterator itr;
    itr = args.cbegin();
    int rows = std::stoi(*itr);
    itr++;
    int cols = std::stoi(*itr);
    itr++;
    for (int r = 0; r < rows; r++)
    {
        std::vector<std::string>::const_iterator end = itr + cols - 1;
        while (end >= itr)
        {
            std::cout << *end;
            if (end > itr)
                std::cout << " ";
            end--;
        }
        std::cout << std::endl;
        itr += cols;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return 0;
    else
    {
        std::vector<std::string> args;
        while(*++argv)
            args.push_back(*argv);
        ft_mirror_matrix(args);
    }
    return 0;
}
