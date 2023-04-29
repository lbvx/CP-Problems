#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int findSize(const vector<vector<char>> &m, int r, int c)
{
    int s = 1;
    while (true)
    {
        if ((r + s >= m.size() || r - s < 0 || c + s >= m[0].size() || c - s < 0) ||
            (m[r + s][c + s] != '#' || m[r + s][c - s] != '#' || m[r - s][c + s] != '#' || m[r - s][c - s] != '#'))
            return s - 1;

        s++;
    }
}

vector<int> countX(const vector<vector<char>> &m, int &n)
{
    vector<int> count(n, 0);
    for (int i = 1; i < m.size() - 1; i++)
    {
        for (int j = 1; j < m[0].size() - 1; j++)
        {
            if (m[i][j] == '#')
            {
                int s = findSize(m, i, j);
                if (s != 0)
                {
                    count[s - 1]++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int n, h, w;
    cin >> h >> w;
    n = min(h, w);
    vector<vector<char>> m(h, vector<char>(w));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> m[i][j];

    vector<int> count = countX(m, n);
    for (auto &a : count)
    {
        cout << a << ' ';
    }
    cout << endl;

    return 0;
}
