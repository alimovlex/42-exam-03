#include <iostream>

void ft_whisper_cipher(std::string &str, int &number)
{
    // Normalize shift bounds to fit perfectly within 0-25
    number %= 26;
    if (number < 0)
        number += 26;

    // C++11 range-based for loop (foreach)
    for (char ch : str)
    {
        unsigned char uc = static_cast<unsigned char>(ch);
        if (std::isupper(uc))
            std::cout << static_cast<char>('A' + (uc - 'A' + number) % 26);
        else if (std::islower(uc))
            std::cout << static_cast<char>('a' + (uc - 'a' + number) % 26);
        else
            std::cout << ch;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return 0;
    else
    {
        std::string str = *++argv;
        int number = std::stoi(*++argv);
        ft_whisper_cipher(str, number);
        return 0;
    }
}
