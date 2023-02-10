#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;

    size_t l = str.size() - 2;

    std::cout << *str.begin() + std::to_string(l) + *(str.end() - 1) << '\n';

    return 0;
}
