#include <bits/stdc++.h>

int main()
{
    int n, m, a, b;
    std::cin >> n >> m;
    std::vector<int> roads(n, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        roads[a - 1]++;
        roads[b - 1]++;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << roads[i] << std::endl;
    }
    return 0;
}
