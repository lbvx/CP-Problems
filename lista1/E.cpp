#include <iostream>
#include <bitset>
#include <algorithm>

int main()
{
    std::bitset<5> con1, con2;
    std::string input;
    while (std::getline(std::cin, input))
    {
        input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
        con1 = (std::bitset<5>) input;

        std::getline(std::cin, input);
        input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
        con2 = (std::bitset<5>) input;

        std::cout << ((con1 ^ con2).all() ? "Y" : "N") << std::endl;
    }
    return 0;
}
