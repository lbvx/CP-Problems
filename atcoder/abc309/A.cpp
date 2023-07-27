// Nine
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (abs(a - b) == 1 && !(a % 3 == 0 && b % 3 == 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
