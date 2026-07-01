#include <stdio.h>

int bracket_validator(char *s) 
{
    char stack[10000]; // Simple stack array assuming reasonable string length
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        char c = s[i];
        
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '[' || c == '{')
            stack[++top] = c; 
        // If it's a closing bracket, check for a match
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (top == -1) 
              return '0'; // Closing bracket with no opening partner
            
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return '0'; // Mismatched brackets
            }
        }
    }
    // If the stack is empty, all brackets were matched perfectly
    return top == -1;
}

int main(int argc, char **argv) 
{
    if (argc < 2) 
    {
        printf("0\n");
        return 0;
    }
    // Pass the first argument (the string to validate) to our function
    if (bracket_validator(argv[1])) 
        printf("1\n");
    else
        printf("0\n");
    return 0;
}
