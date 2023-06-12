// Easy Linear Programming 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, k, sum = 0;
    cin >> a >> b >> c >> k;

    if (k > 0)
    {
        sum += min(a, k);
        k -= min(a, k);
    }
    if (k > 0)
    {
        k -= min(b, k);
    }
    if (k > 0)
    {
        sum -= min(c, k);
        k -= min(c, k);
    }

    cout << sum << endl;
    
    return 0;
}
