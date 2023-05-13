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
    ll p;
    cin >> p;
    ll total = 0;

    for (ll x = 1; x < p; x++)
    {
        if ((powLL(x, p - 1) - 1) % p != 0)
            continue;

        bool pr = true;
        for (ll exp = p - 2; exp > 0; exp--)
        {
            if ((powLL(x, exp) - 1) % p == 0)
            {
                pr = false;
                break;
            }
        }
        if (pr) total++;
    }
    cout << total << endl;

    return 0;
}
