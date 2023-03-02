#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n, k;
    std::cin >> t;

    while (t--)
    {
        std::map<char, int> nLetters;
        std::string str;
        std::cin >> n >> k;
        std::cin >> str;

        for (auto c : str)
        {
            nLetters[c]++;
        }

        int burls = 0;
        for (auto &p : nLetters)
        {
            if (std::islower(p.first))
            {
                auto upper = nLetters.find(std::toupper(p.first));
                if (upper != nLetters.end())
                {
                    while (p.second > 0 && upper->second > 0)
                    {
                        p.second--;
                        upper->second--;
                        burls++;
                    }
                }
            }
        }

        for (auto &p : nLetters)
        {
            if (k == 0)
                break;

            while (p.second > 1)
            {
                p.second -= 2;
                burls++;
                k--;
                if (k == 0)
                    break;
            }
        }

        std::cout << burls << std::endl;
    }

    return 0;
}
