#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a >> b;
    if (!(a % 3 && b % 3 && (a+b) % 3))
        std::cout << "Possible\n";
    else
        std::cout << "Impossible\n";
    
    return 0;
}
