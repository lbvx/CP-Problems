#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == a + b)
        {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
