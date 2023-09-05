// Cat Snuke and a Voyage
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs_r(const vector<set<int>> &graph, set<int> visited, int node, int target, int depth, int maxDepth)
{
    if (depth > maxDepth)
        return false;
   
    visited.insert(node);
    bool ans = false;
    for (auto &neighbor : graph[node])
    {
        if (neighbor == target && depth == 1)
            return true;

        if (visited.find(neighbor) == visited.end())
        {
            ans = ans || dfs_r(graph, visited, neighbor, target, depth + 1, maxDepth);
        }
    }
    return ans;
}

bool dfs(const vector<set<int>> &graph, int start, int target, int maxDepth)
{
    set<int> visited;
    return dfs_r(graph, visited, start, target, 0, maxDepth);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<set<int>> edges(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    cout << (dfs(edges, 1, n, 2) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    
    return 0;
}
