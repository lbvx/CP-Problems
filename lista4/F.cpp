#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    std::map<int, int> count;
    int t, n, in;
    int min;
    
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        min = n + 1;
        while (n--)
        {
            std::cin >> in;
            min = std::min(min, in);
            count[in]++;
        }
        auto mostCommon = std::max_element(count.begin(), count.end(),
                         [] (const std::pair<int, int> & p1, const std::pair<int, int> & p2)
                         {return p1.second < p2.second;});
        std::cout << mostCommon->second / min << '\n';

        count.clear();
    }

    return 0;
}
