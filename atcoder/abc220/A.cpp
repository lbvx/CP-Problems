#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int a, b, c, x;

    cin >> a >> b >> c;

    if (a % c == 0)
        x = a;
    else
        x = a + c - (a % c);

    cout << ((x > b) ? -1 : x) << endl;

    return 0;
}
