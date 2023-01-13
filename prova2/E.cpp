#include <bits/stdc++.h>

using namespace std;

template<typename T>
class SegmentTree // TOPDOWN
{
    int N;
    std::vector<T> ns;

public:
    SegmentTree(const std::vector<T>& xs) : N(xs.size()), ns(4*N, 1) //PRODUTO
    {
        for (size_t i = 0; i < xs.size(); ++i)
            update(i, xs[i]);
    }

    void update(int i, T value)
    {
        update(1, 0, N - 1, i, value);
    }

private:
    void update(int node, int L, int R, int i, T value) {   
        if (i > R or i < L)
            return;
        
        ns[node] *= value;

        if (L == R)
            return;

        update(2*node, L, (L+R)/2, i, value);
        update(2*node + 1, (L+R)/2 + 1, R, i, value);
    } 

public:
    T RSQ(int a, int b)
    {
        return RSQ(1, 0, N - 1, a, b);
    }

private:
    T RSQ(int node, int L, int R, int a, int b)
    {
        if (a > R or b < L)
            return 1;

        if (a <= L and R <= b)
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x * y;
    }

};

unsigned long long pow(unsigned long long b, unsigned long long e)
{
    unsigned long long p = 1;
    while (e--)
        p *= b;

    return p;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, M;
    unsigned long long a, b, y, z;
    cin >> N >> M;

    vector<unsigned long long> nums(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    SegmentTree<unsigned long long> prod(nums);

    while (M--)
    {
        cin >> a >> b >> y >> z;
        // cout << prod.RSQ(a-1, b-1) << '\n';
        // cout << pow(y, z) << '\n';
        if (prod.RSQ(a-1, b-1) < pow(y, z))
        {
            cout << "Sim\n";
        }
        else
        {
            cout << "Nao\n";
        }
    }

    return 0;
}
