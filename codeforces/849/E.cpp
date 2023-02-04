#include <iostream>
#include <vector>
#include <numeric>

long long solve(std::vector<long long> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < 0L && nums[i+1] < 0L)
        {
            nums[i] = -nums[i];
            nums[i+1] = -nums[i+1];
        }
        else if (nums[i] < 0L && nums[i+1] >= 0L)
        {
            if (-nums[i] > nums[i+1])
            {
                nums[i] = -nums[i];
                nums[i+1] = -nums[i+1];
            }
        }
        else if (nums[i] >= 0L && nums[i+1] < 0L)
        {
            if (-nums[i+1] > nums[i])
            {
                nums[i] = -nums[i];
                nums[i+1] = -nums[i+1];
            }
        }
    }
    return std::accumulate(nums.begin(), nums.end(), 0L);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        std::vector<long long> nums(n);

        for (int i = 0; i < n; i++)
            std::cin >> nums[i];

        long long res = solve(nums);

        std::cout << res << "\n";
    }

    return 0;
}
