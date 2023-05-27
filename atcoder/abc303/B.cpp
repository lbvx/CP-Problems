// Discord 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> friends(n, vector<int>(n, 0));
    vector<int> photo(n);

    while (m--)
    {
        for (int i = 0; i < n; i++)
            cin >> photo[i];

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                friends[photo[i] - 1][photo[i - 1] - 1]++;
            if (i != n - 1)
                friends[photo[i] - 1][photo[i + 1] - 1]++;
        }
    }
    
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += count(friends[i].begin(), friends[i].end(), 0);
    }
    total -= n;
    total /= 2;
    cout << total << endl;

    return 0;
}
