// Best Compression Ever
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, b;
    while (cin >> n >> b)
        cout << (1LL << (b + 1) > n ? "yes" : "no") << endl;

    return 0;
}
