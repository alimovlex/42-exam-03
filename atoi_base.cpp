#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

// Helper to get digit value for bases up to 36
int ft_get_digit(char c)
{
    if (std::isdigit(static_cast<unsigned char>(c)))
        return c - '0';
    if (std::isalpha(static_cast<unsigned char>(c)))
        return std::tolower(static_cast<unsigned char>(c)) - 'a' + 10;
    return -1;
}

int ft_atoi_base(const std::string &str, int from_base, int to_base)
{
    std::string::const_iterator it;
    // Step 1: Skip leading whitespace
    for (it = str.begin(); it != str.end() && isspace(*it); ++it);

    // Step 2: Handle optional sign
    int sign = 1;
    if (it != str.end() && (*it == '-' || *it == '+'))
    {
        if (*it == '-')
            sign = -1;
        ++it;
    }

    // Ensure there is at least one digit character remaining
    if (it == str.end())
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    // Step 3: Convert from source base to 64-bit unsigned decimal integer
    unsigned long long decimal = 0;
    while (it != str.end())
    {
        int digit = ft_get_digit(*it);

        if (digit == -1 || digit >= from_base)
        {
            std::cout << "ERROR" << std::endl;
            return 1;
        }

        decimal = (decimal * from_base) + digit;
        ++it;
    }

    // Special case for zero
    if (decimal == 0)
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    // Step 4: Convert from decimal to target base string
    std::string result;
    while (decimal > 0)
    {
        int remainder = decimal % to_base;
        if (remainder < 10)
            result.push_back('0' + remainder);
        else
            result.push_back('A' + remainder - 10);
        decimal /= to_base;
    }

    // Print sign if original number was negative
    if (sign == -1)
        std::cout << "-";

    // Reverse string and output
    std::reverse(result.begin(), result.end());
    std::cout << result << std::endl;

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    std::string str = *++argv;
    int from_base = 0, to_base = 0;

    try
    {
        from_base = std::stoi(*++argv);
        to_base = std::stoi(*++argv);
    }
    catch (const std::exception &e)
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    if (from_base < 2 || from_base > 36 || to_base < 2 || to_base > 36 || str.empty())
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }
    else
        ft_atoi_base(str, from_base, to_base);

    return 0;
}
