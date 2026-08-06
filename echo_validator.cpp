#include <iostream>

bool is_echo_palindrome(const std::string& str)
{
    std::string filtered_str;
    std::string::const_iterator it_start, it_end;
    filtered_str.reserve(str.size());
    // 1. Filter non-alphabetic characters and convert to lower case
    for (unsigned char ch : str)
        if (std::isalpha(ch))
            filtered_str.push_back(static_cast<char>(std::tolower(ch)));
    // 2. Return false if empty
    if (filtered_str.empty())
        return false;

    // 3. Converging iterators
    it_start = filtered_str.cbegin();
    it_end = filtered_str.cend() - 1;

    while (it_start < it_end)
    {
        if (*it_start != *it_end)
            return false;
        it_start++;
        it_end--;
    }

    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "0" << std::endl;
    else
    {
        std::string str = *++argv;
        int res = is_echo_palindrome(str);
        std::cout << res << std::endl;
    }
    return 0;
}
