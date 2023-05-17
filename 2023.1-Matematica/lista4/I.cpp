// Cut the Silver Bar 
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
    cin >> n;
    while(n > 0)
    {
        cout << msb(n) << endl;
        cin >> n;
    }
    return 0;
}
