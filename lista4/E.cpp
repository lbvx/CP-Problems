#include <iostream>
#include <set>

int main()
{
    std::multiset<int> nums;
    int t, a;
    std::cin >> t;
    while (t--)
    {
        std::cin >> a;
        nums.insert(a);
    }
    for (auto c : nums)
    {
        std::cout << c << '\n';
    }
    return 0;
}
