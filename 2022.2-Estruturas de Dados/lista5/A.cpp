#include <iostream>

int main()
{
    int a, b, x;

    std::cin >> a >> x >> b;

    int c = b - a;
    if (c < 0)
        std::cout << "delicious\n";
    else if (c >= 0 && c <= x)
        std::cout << "safe\n";
    else
        std::cout << "dangerous\n";
    
    return 0;
}
