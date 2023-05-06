#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll convert(ll x, ll base)
{
    ll pot = 1;
    ll res = 0;
    for (; x > 0; x /= 10)
    {
        res += (x % 10) * pot;
        pot *= base;
    }
    return res;
}

int main()
{
    ll K, A, B;
    cin >> K >> A >> B;

    cout << convert(A, K) * convert(B, K) << endl;

    return 0;
}
