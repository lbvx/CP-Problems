#include <iostream>
#include <map>
#include <vector>

// a*b+c = (f+e)*d
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> S(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> S[i];
    }

    std::map<long long, int> lhs;
    std::map<long long, int> rhs;

    for (const auto &a : S)
    {
        for (const auto &b : S)
        {
            for (const auto &c : S)
            {
                lhs[a * b + c]++;
            }
        }
    }

    for (const auto &d : S)
    {
        if (d != 0)
            for (const auto &e : S)
            {
                for (const auto &f : S)
                {
                    rhs[(f + e) * d]++;
                }
            }
    }


    int count = 0;
    for (auto &l : lhs)
    {
        auto r = rhs.find(l.first);
        if (r != rhs.end())
        {
            count += l.second * (*r).second;
        }
    }

    std::cout << count << '\n';

    return 0;
}
