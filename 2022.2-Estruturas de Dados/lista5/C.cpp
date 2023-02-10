#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
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

    int max_size()
    {
        return *std::max_element(size.begin(), size.end());
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> m;
    int c, r;
    std::cin >> c >> r;

    while (c != 0)
    {
        UFDS ufds(c);

        std::string b1, b2;
        for (int i = 0; i < c; i++)
        {
            std::cin >> b1;
            m[b1] = i;
        }
        for (int i = 0; i < r; i++)
        {
            std::cin >> b1 >> b2;
            ufds.union_set(m[b1], m[b2]);
        }

        std::cout << ufds.max_size() << std::endl;

        std::cin >> c >> r;
    }
    return 0;
}
