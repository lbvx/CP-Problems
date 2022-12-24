#include <iostream>
#include <algorithm>

bool isEven(std::string::iterator b, std::string::iterator e)
{
    int d = std::distance(b, e);
    if (d & 1) // tamanho impar
    {
        return false;
    }

    if (std::string(b, b+d/2) == std::string(b+d/2, e))
        return true;
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string str;
    std::cin >> str;

    std::string::iterator p = str.end()-1;
    while (true)
    {
        if (isEven(str.begin(), p))
        {
            std::cout << std::distance(str.begin(), p) << '\n';
            return 0;
        }
        p--;
    }
    return 0;
}
