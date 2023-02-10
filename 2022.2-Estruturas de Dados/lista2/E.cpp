#include <stack>
#include <iostream>

int precedence(char op)
{
    switch (op)
    {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

bool isSymbol(char c)
{
    switch (c)
    {
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
            return true;
        default:
            return 0;
    }
}

std::string infixToPostfix(std::string infix)
{
    std::stack<char> stacc;
    std::string postfix;

    for (auto c : infix)
    {
        if (!isSymbol(c))
            postfix += c;
        else if (c == '(') 
            stacc.push('(');
        else if (c == ')')
        {
            while (stacc.top() != '(')
            {
                postfix += stacc.top();
                stacc.pop();
            }
            stacc.pop();
        }
        else
        {
            while (!stacc.empty() && precedence(c) <= precedence(stacc.top()))
            {
                postfix += stacc.top();
                stacc.pop();
            }
            stacc.push(c);
        }
    }
    while (!stacc.empty())
    {
        postfix += stacc.top();
        stacc.pop();
    }
    return postfix;
}

int main()
{
    std::string infix, postfix, in;
    int n;
    std::cin >> n;
    std::getline(std::cin, in);
    std::getline(std::cin, in);
    for (int i = 0; i < n; i++)
    {
        infix = "";
        std::getline(std::cin, in);
        while (in != "")
        {
            infix += in;
            std::getline(std::cin, in);
        }
        // std::cout << infix << std::endl;
        postfix = infixToPostfix(infix);
        std::cout << postfix;
        if (i != n - 1)
            std::cout << '\n';
        std::cout << std::endl;
    }
    return 0;    
}
