// Help is needed for Dexter
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int msb(ll x)
{
    int b = 0;
    while (x >>= 1)
        b++;
    return b;
}

int main()
{
    int n;
    while(cin >> n)
        cout << msb(n) + 1 << endl;
    return 0;
}
