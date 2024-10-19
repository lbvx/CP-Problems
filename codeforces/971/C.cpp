// The Legend of Freya the Frog
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MULTIPLE
void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    ll result_x = (x + k - 1) / k * 2 - 1;
    ll result_y = (y + k - 1) / k * 2;

    cout << max(result_x, result_y) << endl;;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    #ifdef MULTIPLE
    cin >> t;
    #endif

    for (int i = 0; i < t; i++)
        solve();
    
    return 0;
}
