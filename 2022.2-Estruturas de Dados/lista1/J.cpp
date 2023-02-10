#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> minIndexMatrix(std::vector<std::vector<int>> m)
{
    std::pair<int, int> min(0, 0);
    for (int i = 0; i < m.size(); i++)
        for (int j = 0; j < m[i].size(); j++)
            if (m[i][j] < m[min.first][min.second])
            {
                min.first = i;
                min.second = j;
            }

    return min;
}

int main()
{
    int t, streets, avenues, friends;

    // distancias totais que sera calculada de cada espaco no mapa
    std::vector<std::vector<int>> distances;
    // posicoes das casas
    std::vector<std::pair<int, int>> homes;

    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> streets >> avenues >> friends;

        distances = std::vector<std::vector<int>>(streets,
            std::vector<int>(avenues, 0));
        homes = std::vector<std::pair<int, int>>(friends, std::pair<int, int>(0, 0));

        for (int i = 0; i < friends; i++)
        {
            std::cin >> homes[i].first >> homes[i].second;
        }
        
        for (int i = 0; i < streets; i++)
        {
            for (int j = 0; j < avenues; j++)
            {
                for (auto home: homes)
                {
                    distances[i][j] += std::abs((i - home.first)) + std::abs((j - home.second));
                }
            }
        }

        std::pair<int, int> meetPoint(minIndexMatrix(distances));
        std::cout << "(Street: " << meetPoint.first << ", Avenue: " << meetPoint.second << ")" << std::endl;
    }

    return 0;
}
