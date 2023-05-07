#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll powLL(ll b, ll p)
{
    if (p == 0LL)
        return 1LL;
    if (b == 0LL)
        return 0LL;

    ll res = 1;
    while (p--)
    {
        res *= b;
    }
    return res;
}

int main()
{
    ll x;
    while (cin >> x)
    {
        string cfs;
        getline(cin, cfs);
        getline(cin, cfs);

        vector<ll> coefs;
        size_t p;
        size_t l = 0;
        while ((p = cfs.find(' ', l)) != string::npos)
        {
            string numstr = cfs.substr(l, p - l);
            coefs.push_back(stoi(numstr));
            l = p + 1;
        }

        ll res = 0LL;
        for (int i = 0; i < coefs.size(); i++)
        {
            ll n = coefs.size() - i;
            res += n * (powLL(x, n - 1)) * coefs[i];
        }
        cout << res << endl;
    }
    return 0;
}
