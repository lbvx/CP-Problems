#include <iostream>
#include <vector>
#include <set>

int count(std::string str, int spl)
{
    std::set<char> a, b;
    for (int i = 0; i < spl; i++)
    {
        a.insert(str[i]);
    }
    for (int i = spl; i < str.size(); i++)
        b.insert(str[i]);

    return a.size() + b.size();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    std::string in;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> in;

        int max = 0;
        for (int spl = 0; spl < in.size(); spl++)
        {
            // std::cout << count(in, spl) << " ";
            max = std::max(max, count(in, spl));
        }
        std::cout << max << "\n";
    }

    return 0;
}
