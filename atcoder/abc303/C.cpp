// Dash
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(string moves, set<pair<int, int>> potions, int n, int h, int k)
{
    pair<int, int> position{0, 0};
    int i = 0;

    for (const char &c : moves)
    {
        if (c == 'U')
            position.second += 1;
        else if (c == 'D') 
            position.second -= 1;
        else if (c == 'L')
            position.first -= 1;
        else if (c == 'R')
            position.first += 1;

        h--;
        auto p = potions.find(position);
        if (h < k && p != potions.end())
        {
            h = k;
            potions.erase(p);
        }
        i++;
        if (h <= 0 && i != n)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h, k;
    string moves;
    cin >> n >> m >> h >> k;
    cin >> moves;
    set<pair<int, int>> potions;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        potions.emplace(x, y);
    }

    cout << (solve(moves, potions, n, h, k) ? "Yes" : "No") << endl;

    return 0;
}
