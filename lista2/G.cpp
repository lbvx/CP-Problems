#include <queue>
#include <iostream>
#include <vector>

using ii = std::pair<int, int>;

int main()
{
    int t, n, m;
    std::vector<ii> list;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        list = std::vector<ii>(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> list[i].first;
            list[i].second = i;
        }

        std::priority_queue<ii> pq(list.begin(), list.end());
        int count = 1;
        while(!pq.top().second)
        {
            count++;
            pq.pop();
        }

        std::cout << count << std::endl;
    }
    return 0;
}
