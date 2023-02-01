#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, d;
    std::cin >> n >> d;
    std::vector<long long> coords(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> coords[i];
    }

    int count = 0;
    for (auto l = coords.begin(); l < coords.end() - 2; l++)
    {
        for (auto r = l + 2; r < coords.end(); r++)
        {
            if (*r - *l <= d)
            {
                count += std::distance(l, r) - 1;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}
