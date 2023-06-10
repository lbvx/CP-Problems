// Sleep Log 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, li, ri;
    cin >> n;

    vector<ll> sleepLog(n);
    for (int i = 0; i < n; i++)
        cin >> sleepLog[i];

    cin >> q;
    while (q--)
    {
        cin >> li >> ri;
        ll sleepTime = 0;

        auto left = lower_bound(sleepLog.begin(), sleepLog.end(), li);
        if (distance(sleepLog.begin(), left) & 1)
        {
            sleepTime += *(left + 1) - *left;
            left++;
        }
        else
        {
            sleepTime += *left - li;
        }

        auto right = lower_bound(sleepLog.begin(), sleepLog.end(), ri);
        if (distance(sleepLog.begin(), right) & 1)
        {
            right--;
        }
        else
        {
            sleepTime += ri - *(right - 1);
            right -= 2;
        }

        while (left < right)
        {
            sleepTime += *(left + 2) - *(left + 1);
            left += 2;
        }

        cout << sleepTime << endl;
    }
    
    return 0;
}
