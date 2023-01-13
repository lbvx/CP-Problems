#include <bits/stdc++.h>

using namespace std;

template<typename T>
class BITree {
private:
    vector<T> ts;
    size_t N;

public:
    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    T RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

private:
    int LSB(int n) { return n & (-n); }

    T RSQ(int i)
    {
        T sum = 0;

        while (i >= 1)
        {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

public:
    void add(size_t i, const T& x)
    {
        if (i == 0)
            return;

        while (i <= N)
        {
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
            std::cout << "bing\n";
            std::cin >> s >> e;
            for (int i = s; i < e; i++)
            {
                std::cout << "asd\n";
                bt.add(i, 1);
            }
        }

        std::cout << bt.RSQ(1, n) << '\n';
    }
    
    return 0;
}
