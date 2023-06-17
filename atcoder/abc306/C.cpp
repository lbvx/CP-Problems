// Centers
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> occurrences(n + 1, 0);
    vector<pair<int, int>> centers(n + 1);

    int ai;
    for (int i = 0; i < centers.size(); i++)
        centers[i].second = i;
    for (int i = 0; i < 3*n; i++)
    {
        cin >> ai;
        occurrences[ai]++;
        if (occurrences[ai] == 2)
        {
            centers[ai].first = i;
        }
    }

    sort(centers.begin(), centers.end());
    for (int i = 1; i < centers.size(); i++)
        cout << centers[i].second << (i == centers.size() - 1 ? '\n' : ' ');
    
    return 0;
}
