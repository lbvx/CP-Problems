#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<std::string> dream;
    std::string in;
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> in;
        if (in == "Sleep")
        {
            std::cin >> in;
            dream.push(in); 
        }
        else if (in == "Test")
        {
            if (dream.empty())
                std::cout << "Not in a dream" << std::endl;
            else
                std::cout << dream.top() << std::endl;
        }
        else if (in == "Kick" && !dream.empty())
            dream.pop();
    }

    return 0;
}
