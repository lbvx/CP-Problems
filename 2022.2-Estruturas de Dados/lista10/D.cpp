#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string in;
    int t, n, k;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> k >> in;
        int count = 0;
        int boys = 0;

        auto l = in.begin();
        auto r = l;
        if (*l == '1')
            boys++;

        while (l < in.end())
        {
            if (boys > k || r == in.end())
            {
                if (*l == '1')
                    boys--;
                l++;
            }
            else if (boys <= k)
            {
                r++;
                if (*r == '1')
                    boys++;
            }
            if (boys == k)
            {
                count++;
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}
