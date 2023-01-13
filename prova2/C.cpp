#include <bits/stdc++.h>

using namespace std;

class UFDS
{
private:
    std::vector<int> size, ps;

public:
    UFDS(int N) : size(N + 1, 1), ps(N + 1)
    {
        std::iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x) const
    {
        return x == ps[x] ? x : find_set(ps[x]);
    }

    bool same_set(int x, int y)
    {
        return find_set(x) == find_set(y);        
    }

    void union_set(int x, int y)
    {
        if (same_set(x, y))
            return;

        int p = find_set(x);
        int q = find_set(y);

        if (size[p] < size[q])
            std::swap(p, q);

        ps[q] = p;
        size[p] += size[q];
    }

    int get_size(int x)
    {
        return size[x];
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, C, x, y;

    cin >> N >> M >> C;
    UFDS suspeitos(N);

    while (C--)
    {
        cin >> x >> y;
        suspeitos.union_set(x, y);
    }
    set<pair<int, int>> tamanhos; // par raiz, tamanho
    for (int i = 1; i <= N; i++)
    {
        // cout << i << " - pai " << suspeitos.find_set(i) << " - tamanho" << suspeitos.get_size(i) << '\n';
        int pai = suspeitos.find_set(i);
        tamanhos.emplace(pai, suspeitos.get_size(pai));
        // tamanhos.insert(pair<int,int>(suspeitos.find_set(i), suspeitos.get_size(i)));
    }

    int quadrilhas = 0;
    int maior = 0;
    for (auto &a : tamanhos)
    {
        // cout << a.first << ':' << a.second << '\n';
        if (a.second >= M)
        {
            quadrilhas++;
        }
        maior = max(maior, a.second);
    }

    cout << quadrilhas;
    if (quadrilhas > 0)
        cout << ' ' << maior;
    cout << '\n';

    return 0;
}
