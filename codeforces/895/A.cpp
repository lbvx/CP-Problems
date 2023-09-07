// Two Vessels
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b, c;
    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;
        if (a - b == 0)
            cout << '0' << endl;
        else 
            cout << 1 + (abs(a - b) - 1) / (2 * c) << endl;
    }

    return 0;
}
