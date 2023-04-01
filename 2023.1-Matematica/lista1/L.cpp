#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long x;

    cin >> x;

    long long res = (x + 1)/ 2LL;

    if (x & 1)
        res = -res;

    cout << res << endl;

    return 0;
}
