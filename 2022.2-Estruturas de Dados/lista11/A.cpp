#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, a, b;
    std::cin >> x >> a >> b;

    std::cout << (std::abs(x - a) < std::abs(x - b) ? "A\n" : "B\n");

    return 0;
}
