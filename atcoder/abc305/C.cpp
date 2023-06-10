// Snuke the Cookie Picker  
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];


    int iS = 0, jS = 0;
    while (grid[iS][jS] != '#')
    {
        jS++;
        if (jS == w)
        {
            jS = 0;
            iS++;
        }
    }
    int jF;
    pair<int, int> eaten{0, 0};
    bool found = false;
    if (jS > 0 && iS < h - 1 && grid[iS + 1][jS - 1] == '#')
        {
            eaten.first = iS;
            eaten.second = jS - 1;
            found = true;
        }

    else
    {
        jF = jS;
        
        while (jF < w - 1 && grid[iS][jF + 1] == '#')
            jF++;

        if (jF < w - 2 && grid[iS][jF + 2] == '#')
        {
            eaten.first = iS;
            eaten.second = jF + 1;
            found = true;
        }
        if (jF < w - 1 && iS < h - 1 && grid[iS + 1][jF + 1] == '#')
        {
            eaten.first = iS;
            eaten.second = jF + 1;
            found = true;
        }
    }

    if (!found)
    {
        for (int i = iS; i < h; i++)
        {
            for (int j = jS; j <= jF; j++)
            {
                if (grid[i][j] != '#')
                {
                    eaten.first = i;
                    eaten.second = j;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
    }

    cout << eaten.first + 1 << ' ' << eaten.second + 1 << endl;
    
    return 0;
}
