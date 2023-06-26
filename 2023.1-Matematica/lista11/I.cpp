// Pasha and Stick  
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count = 0;
    if (!(n & 1))
    {
        count = n / 2 - 1;
        if (n % 4 == 0)
            count--;
        count /= 2;
    }
    cout << count << endl;
    
    return 0;
}
