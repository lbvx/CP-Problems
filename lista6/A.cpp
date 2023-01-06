#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, s;
    std::cin >> a >> b >> c;
    s = a+b;
    s = std::min(s, b+c);
    s = std::min(s, a+c);
    std::cout << s << '\n';
    return 0;
}
