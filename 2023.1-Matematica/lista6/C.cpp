// Next Prime
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool prime(ll x)
{
    if (x % 2 == 0)
        return false;
    for (ll i = 3; i*i < x; i += 2LL)
        if (x % i == 0)
            return false;
    return true;
}

ll solve(ll x)
{
    if (x == 2)
        return 2;
    if (x % 2 == 0)
        x++;
    while (true)
    {
        if (prime(x))
            return x;
        x++;
    }
}

int main()
{
    int x;
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}
