#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto cmp = [](const std::pair<int, int>& l, const std::pair<int, int>& r)
    {
        if (l.second == r.second)
            return l.first > r.first;

        return l.second < r.second;
    };

    int N;
    std::cin >> N;
    int tcase = 1;
    while (N)
    {
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int,int>>,
                            decltype(cmp)> pq(cmp);

        for (int i = 0; i < N; i++)
        {
            int brief, exec;
            std::cin >> brief >> exec;
            pq.emplace(brief, exec);
        }

        int briefSum = 0;
        int remTime;
        std::pair<int, int> m = pq.top();
        pq.pop();
        briefSum += m.first;
        remTime = m.second;
        for (int i = 1; i < N; i++)
        {
            m = pq.top();
            pq.pop();
            briefSum += m.first;
            remTime -= m.first;
            remTime = std::max(remTime, m.second);
        }
        briefSum += remTime;

        std::cout << "Case " << tcase << ": " << briefSum << "\n";

        tcase++;
        std::cin >> N;
    }

    return 0;
}
