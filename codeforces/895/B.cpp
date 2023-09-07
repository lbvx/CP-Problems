// The Corridor or There and Back Again
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> traps;
        for (int i = 0; i < n; i++)
        {
            int di, si;
            cin >> di >> si;
            traps.emplace(di, si);
        }

        int maxK = INT_MAX;
        while (!traps.empty())
        {
            auto trap = traps.top();
            traps.pop();

            maxK = min(maxK, trap.first + (trap.second - 1) / 2);
        }
        cout << maxK << endl;
    }
    
    return 0;
}
