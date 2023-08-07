// 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string x;
        cin >> x;

        ll k = -1;
        bool beq5 = true;
        ll lim = x.size() - 1;
        while (beq5)
        {
            bool broke = false;
            for (ll i = 0; i <= lim; i++)
            {
                if (x[i] >= '5')
                {
                    k = i;
                    broke = true;
                    break;
                }
            }
            if (!broke)
            {
                break;
            }

            for (ll i = k; i <= lim; i++)
            {
                x[i] = '0';
            }
            if (k == 0)
            {
                x = "1" + x;
                beq5 = false;
            }
            else
                x[k - 1]++;

            // cout << x[k] << ' ' << k << endl;
        }

        cout << x << endl;
    }
    
    return 0;
}
