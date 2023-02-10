#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> nums[i];
        }

        int count = 0;
        for (auto l = nums.begin(); l < nums.end(); l++)
        {
            int sum = 0;
            for (auto r = l; r < nums.end(); r++)
            {
                sum += *r;
                // std::cout << "soma parcial = " << sum << '\n';
                if (sum == 0)
                    count++;
            }
        }
        std::cout << count << '\n';
    }

    return 0;
}
