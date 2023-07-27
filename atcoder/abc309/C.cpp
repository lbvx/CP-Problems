// Medicine
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> meds(n);

    for (int i = 0; i < n; i++)
    {
        cin >> meds[i].first >> meds[i].second;
    }

    sort(meds.begin(), meds.end(), greater<>());

    ll sum = 0;
    int i = 0;
    while (sum <= k)
    {
        sum += meds[i].second;
        i++;
    }

    cout << meds[i - 1].first + 1 << endl;
    
    return 0;
}
