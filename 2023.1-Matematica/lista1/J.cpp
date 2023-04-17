#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    map<int, int> cds;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
            
        int in, rep = 0;
        for (int i = 0; i < n + m; i++)
        {
            cin >> in;
            cds[in]++;
            if (cds[in] == 2)
                rep++;
        }
        cout << rep << '\n';
        cds.clear();
    }
    
    return 0;
}
