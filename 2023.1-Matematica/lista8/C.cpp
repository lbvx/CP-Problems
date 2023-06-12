// Drinks 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    double totalP = 0.0, percentage;
    for (int i = 0; i < n; i++)
    {
        cin >> percentage;
        totalP += percentage;
    }
    
    cout << (totalP / n) << endl;
    
    return 0;
}
