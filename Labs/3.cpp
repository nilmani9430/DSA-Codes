#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
bool isWhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
bool isArithmeticExpression(const char *expression)
{
    int length = strlen(expression);
    bool expectingOperator = false;
    for (int i = 0; i < length; i++)
    {
        char c = expression[i];
        if (isWhitespace(c))
        {
            continue;
        }
        if (isDigit(c))
        {
            if (!expectingOperator)
            {
                return false;
            }
            expectingOperator = !expectingOperator;
        }
        else if (isOperator(c))
        {
            if (expectingOperator)
            {
                return false;
            }
            expectingOperator = !expectingOperator;
        }
        else
        {
            return false;
        }
    }
    return !expectingOperator;
}
int main()
{
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    if (isArithmeticExpression(expression))
    {
        printf("Valid arithmetic expression.\n");
    }
    else
    {
        printf("Invalid arithmetic expression.\n");
    }
    return 0;
}
