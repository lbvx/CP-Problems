#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> users;
    int n, u;
    cin >> n;
    while (n--)
    {
        cin >> u;
        users.insert(u);
    }
    cout << users.size() << endl;
    return 0;
}
