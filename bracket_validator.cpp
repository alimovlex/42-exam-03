#include <string>
#include <stack>

// Helper to check if a character is an opening bracket
bool is_open(char c)
{
    return (c == '(' || c == '[' || c == '{');
}

// Helper to check if an opening and closing pair match
bool matches(char open, char close)
{
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

int ft_bracket_validator(const std::string &str)
{
    std::stack<char> stk;

    for (char c : str)
    {
        if (is_open(c))
            stk.push(c);
        else if (c == ')' || c == ']' || c == '}')
        {
            // If empty, we have an unmatched closing bracket
            if (stk.empty())
                return 1;
            char open = stk.top();
            stk.pop();
            if (!matches(open, c))
                return 1; // Mismatched bracket types
        }
    }

    // 0 = valid (stack is empty), 1 = invalid (unmatched opening brackets left over)
    if (stk.empty())
        return 0;
    else
     return 1;
}

int main(int argc, char **argv)
{
    int validator = 0;
    if (argc < 2)
        return validator;
    else
    {
        std::string str = *++argv;
        int validator = ft_bracket_validator(str);
        return validator;
    }
    return validator;
}
