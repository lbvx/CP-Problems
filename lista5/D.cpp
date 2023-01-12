#include <vector>
#include <numeric>
#include <iostream>
#include <map>

class UFDS
{
private:
    std::vector<int> size, ps;

public:
    UFDS(int N) : size(N + 1, 1), ps(N + 1)
    {
        // ps = {0, 1, 2, 3, ..., N}
        std::iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x) const
    {
        return x == ps[x] ? x : find_set(ps[x]);
    }

    int find_set_compressao(int x)
    {
        return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
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
};

bool check(std::vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != x)
            return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, n, m;
    std::cin >> N;
    std::map<int, int> fr; // amigo: valor
    
    while (N--)
    {
        std::cin >> n >> m;
        UFDS ufds(n);
        int in1, in2;
        for (int i = 0; i < n; i++)
        {
            std::cin >> in1;
            fr[i] = in1;
        }
        for (int i = 0; i < m; i++)
        {
            std::cin >> in1 >> in2;
            ufds.union_set(in1, in2);
        }

        std::vector<int> sums(n, 0);
        for (int i = 0; i < n; i++)
        {
            sums[ufds.find_set(i)] += fr[i];
        }
        std::cout << (check(sums, 0) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }

    return 0;
}
