#include <iostream>
#include <vector>
#include <algorithm>

int median(std::vector<int> v)
{
    std::sort(v.begin(), v.end());
    return v[(v.size() - 1) / 2];
}

int main()
{
    int t, streets, avenues, friends;

    std::vector<int> homesX;
    std::vector<int> homesY;

    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> streets >> avenues >> friends;

        homesX = std::vector<int>(friends);
        homesY = std::vector<int>(friends);


        for (int k = 0; k < friends; k++)
        {
            std::cin >> homesX[k] >> homesY[k];
        }
        
        std::pair<int, int> meetPoint(0, 0);
        meetPoint.first = median(homesX);
        meetPoint.second = median(homesY);
        std::cout << "(Street: " << meetPoint.first << ", Avenue: " << meetPoint.second << ")" << std::endl;
    }

    return 0;
}
