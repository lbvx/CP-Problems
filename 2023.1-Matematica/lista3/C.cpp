#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll powLL(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int main()
{
    ll x;
    while (cin >> x)
    {
        string cfs;
        getline(cin, cfs);
        getline(cin, cfs);

        stringstream ss(cfs);
        ll c;
        vector<ll> coefs;
        while (ss >> c)
        {
            coefs.push_back(c);
        }

        ll res = 0LL;
        for (size_t i = 0; i < coefs.size(); i++)
        {
            ll n = coefs.size() - i - 1;
            // cout << "n=" << n << " coef=" << coefs[i] << " x=" << x << endl;
            if (n != 0)
                res += n * powLL(x, n - 1) * coefs[i];
        }
        cout << res << endl;

    }
    return 0;
}
