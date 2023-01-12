#include <iostream>

int main()
{
    int n;
    
    std::cin >> n;

    int r = 1;
    while ((r <<= 1) <= n);
    r >>= 1;
    std::cout << r << '\n';

    return 0;
}
