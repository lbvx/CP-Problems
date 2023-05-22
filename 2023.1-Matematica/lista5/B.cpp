// Between a and b ...
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll t = 0;

    if (a % x == 0)
        t++;
    
    a = a + x - (a % x);
    b = b - (b % x);
    t += (b - a + x) / x;

    cout << t << endl;

    return 0;
}
