// Minimize! 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, a, b;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        cout << (-a + b) << endl;
    }

    return 0;
}
