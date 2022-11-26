#include <iostream>
#include <set>

int main()
{
    std::set<char> letters;
    std::string in;
    std::cin >> in;
    for (char c : in)
    {
        if (letters.find(c) == letters.end())
            letters.insert(c);
        else
        {
            std::cout << "no" << std::endl;
            return 0;
        }
    }
    std::cout << "yes" << std::endl;
    return 0;
}
