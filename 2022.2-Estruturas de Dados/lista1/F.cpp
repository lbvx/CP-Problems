#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int j, r, p;
    std::vector<int> points;
    while (std::cin >> j >> r)
    {
        points = std::vector<int>(j, 0);

        for (int i = 0; i < j * r; i++)
        {
            std::cin >> p;
            points[i % j] += p;
        }

        std::reverse(points.begin(), points.end());
        std::cout << j - (std::distance(points.begin(), std::max_element(points.begin(), points.end())))
                  << std::endl;

    }
    return 0;
}
