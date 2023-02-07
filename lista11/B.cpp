#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (s.find(c) == s.npos)
        {
            std::cout << c << "\n";
            return 0;
        }
    }
    std::cout << "None\n";
    return 0;
}
