// Design Tutorial: Learn from Math
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool prime(ll x)
{
    if (x % 2 == 0)
        return false;
    for (ll i = 3; i*i <= x; i += 2LL)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    ll n;
    cin >> n;
    ll x, y;
    
    x = 4;
    y = n - 4;
    while (prime(x) || prime(y))
    {
        x++; y--;
    }
    cout << x << " " << y << endl;

    return 0;
}
