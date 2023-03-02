#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        long long card;
        long long totalPower = 0;
        std::priority_queue<long long> bonusCards;
        for (int i = 0; i < n; i++)
        {
            std::cin >> card;
            if (card == 0LL)
            {
                if (!bonusCards.empty())
                {
                    totalPower += bonusCards.top();
                    bonusCards.pop();
                }
            }
            else
            {
                bonusCards.push(card);
            }
        }

        std::cout << totalPower << std::endl;
    }

    return 0;
}
