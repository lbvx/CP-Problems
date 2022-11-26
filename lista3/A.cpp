#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    a += b;
    std::cout << ((a >= 10) ? "error" : std::to_string(a) ) << std::endl;
    return 0;
}
