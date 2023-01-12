#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
	std::vector<std::vector<int>> ar;
	int k;
	while (std::cin >> k)
	{
        ar = std::vector<std::vector<int>>(k, std::vector<int>(k));
		for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                std::cin >> ar[i][j];
            }
        }

        for (auto &a : ar)
        {
            std::sort(a.begin(), a.end());
        }

        std::vector<std::vector<int>> smallest(k, std::vector<int>(2));
        for (int i = 0; i < k; i++)
        {
            smallest[i][0] = ar[i][0];
            smallest[i][1] = ar[i][1];
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> sums;

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                
            }
        }
	}
	return 0;
}
