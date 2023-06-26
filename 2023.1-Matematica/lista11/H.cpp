// Mislove Has Lost an Array 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> powers;
    int count = 0, p = 1;
    while (count < r)
    {
        powers.push_back(p);
        p <<= 1;
        count++;
    }
    
    ll minSum = accumulate(powers.begin(), powers.begin() + l, n - l);
    ll maxSum = accumulate(powers.begin(), powers.end(), (ll) powers.back() * (n - r));
    cout << minSum << ' ' << maxSum << endl;
    
    return 0;
}
