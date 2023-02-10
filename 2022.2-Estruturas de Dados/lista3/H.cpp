#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::string> slogans;
    std::string firstLine, secondLine;
    int n;
    std::cin >> n;
    std::getchar();

    while (n--)
    {
        std::getline(std::cin, firstLine);
        std::getline(std::cin, secondLine);
        slogans[firstLine] = secondLine;
    }
    std::cin >> n;
    std::getchar();
    while (n--)
    {
        std::getline(std::cin, firstLine);
        std::cout << slogans[firstLine] << std::endl;;
    }
    return 0;
}
