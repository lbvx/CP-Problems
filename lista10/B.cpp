#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int s1, s2, e1, e2;
    std::cin >> s1 >> e1 >> s2 >> e2;
    int r = std::min(e1, e2) - std::max(s1, s2);
    std::cout << std::max(0, r) << '\n';

    return 0;
}
