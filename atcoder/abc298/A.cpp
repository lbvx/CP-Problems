#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string in;

    cin >> n >> in;

    int g = count(in.begin(), in.end(), 'o');
    int p = count(in.begin(), in.end(), 'x');

    if (g > 0 && p == 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
