// Plus Minus Permutation
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        // multiplos de x E de y
        ll xyMul = n / lcm(x, y);
        // multiplos apenas de x e apenas de y
        ll xMul = n / x - xyMul, yMul = n / y - xyMul;

        ll score = (n + (n - xMul + 1)) * xMul / 2;
        score -= (1 + yMul) * yMul / 2;

        cout << score << endl;
    }
    
    return 0;
}
