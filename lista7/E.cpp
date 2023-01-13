#include <bits/stdc++.h>

using namespace std;

template<typename T>
class BITree {
public:
    // É preciso adicionar um elemento sentinela na última posição para evitar o 
    // erro 'off-by-one' na implementação de range_add()
    BITree(size_t n) : ts(n + 2, 0), N(n) {}        

    ll value_at(int i) { return RSQ(i); }

    void range_add(size_t i, size_t j, ll x)
    {
        add(i, x);
        add(j + 1, -x);
    }

private:
    vector<T> ts;
    size_t N;

    int LSB(int n) { return n & (-n); }

    ll RSQ(int i)
    {
        ll sum = 0;

        while (i >= 1) {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

    void add(size_t i, ll x)
    {
        while (i <= N) {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

int main()
{
    int t, n;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        BITree<int> bt(n);

        int s, e;
        for (int k = 0; k < n; k++)
        {
            std::cin >> s >> e;
            bt.range_add(s, e, 1);
        }

        int maior = bt.value_at(1);
        for (int i = 0; i < n;)

    }
    
    return 0;
}
