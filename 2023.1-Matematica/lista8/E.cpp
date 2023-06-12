// Cells Not Under Attack 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    set<ll> attackedRows, attackedColumns;
    ll freeCells = n * n;
    ll rookRow, rookColumn;

    for (int i = 0; i < m; i++)
    {
        cin >> rookRow >> rookColumn;

        if (attackedRows.find(rookRow) == attackedRows.end())
        {
            freeCells -= n - attackedColumns.size();
            attackedRows.insert(rookRow);
        }
        if (attackedColumns.find(rookColumn) == attackedColumns.end())
        {
            freeCells -= n - attackedRows.size();
            attackedColumns.insert(rookColumn);
        }
        
        cout << freeCells << " \n"[i == m - 1 ? 1 : 0];
    }
    
    return 0;
}
