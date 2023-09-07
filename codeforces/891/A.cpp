// Array Coloring
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, elem;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int odd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> elem;
            odd += elem & 1;
        }

        cout << (odd & 1 ? "No" : "Yes") << endl;
    }
    
    return 0;
}
