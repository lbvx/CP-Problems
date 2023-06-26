// Badges 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, g, n;
    cin >> b >> g >> n;

    b = min(b, n);
    g = min(g, n);
    cout << b + g - n + 1 << endl;
    
    return 0;
}
