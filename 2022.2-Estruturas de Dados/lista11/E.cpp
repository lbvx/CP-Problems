#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int f, s;
    while (std::cin >> f)
    {
        std::cin >> s;
        int diff = s - f;
        std::cout << (s + diff - 1) / diff << "\n"; // ceil(slow / diff)
    }
    
    return 0;
}
