// Add One Edge
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bfs(const vector<set<int>> &graph, int node, vector<ll> &dists)
{
    set<int> v;
    queue<int> q;
    dists[node] = 0;
    v.insert(node);
    ll max_dist = 0;

    q.push(node);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (const int &neighbour : graph[n])
        {
            if (v.find(neighbour) == v.end())
            {
                dists[neighbour] = dists[n] + 1;
                max_dist = max(max_dist, dists[neighbour]);
                v.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
    return max_dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<set<int>> graph(n1 + n2 + 1);

    for (int i = 0; i < m; i++)
    {
        int ai, bi;
        cin >> ai >> bi;
        graph[ai].insert(bi);
        graph[bi].insert(ai);
    }

    vector<ll> dists(n1 + n2 + 1, 0);
    ll g1_max = bfs(graph, 1, dists);
    ll g2_max = bfs(graph, n1 + n2, dists);

    cout << g1_max + g2_max + 1 << endl;
    
    return 0;
}
