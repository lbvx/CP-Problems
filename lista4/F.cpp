#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<std::set<int>> ars;
    int t, n, in;

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        if (ars.empty())
        {
            ars.push_back(std::set<int>());
        }
        while (n--)
        {
            std::cin >> in;
            bool added = false;
            for (auto &s : ars)
            {
                if (s.find(in) == s.end())
                {
                    // std::cout << "nao tem " << in << '\n';
                    s.insert(in);
                    added = true;
                    break;
                }
            }
            if (!added)
            {
                // std::cout << "criando novo\n";
                std::set<int> ne;
                ne.insert(in);
                ars.push_back(ne);
            }
        }
        std::cout << ars.size() << '\n';
        ars.clear();
    }

    return 0;
}
