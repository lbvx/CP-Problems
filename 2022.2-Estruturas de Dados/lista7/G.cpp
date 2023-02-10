#include <bits/stdc++.h>

template<typename T>
class SegmentTree // TOPDOWN
{
    int N;
    std::vector<T> ns;

public:
    SegmentTree(const std::vector<int>& xs) : N(xs.size()), ns(4*N, INT_MAX)
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
        // Caso base: i não pertence ao intervalo [L, R]
        if (i > R or i < L)
            return;
        
        // ns[node] += value;
        ns[node] = std::min(ns[node], value);

        // Caso base: node é uma folha
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
        if (a > R or b < L)         // [a, b] ∩ [L, R] = {∅}
            return INT_MAX;

        if (a <= L and R <= b)      // [L, R] ⊂ [a, b] 
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return std::min(x, y);
    }

};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T, N, Q;
    std::cin >> T;

    for (int s = 0; s < T; s++)
    {
        std::cin >> N >> Q;
        std::vector<int> pontos(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> pontos[i];
        }
        SegmentTree<int> st(pontos);
        std::cout << "Scenario #" << (s+1) << ":\n";
        for (int i = 0; i < Q; i++)
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << st.RSQ(l-1, r-1) << '\n';
        }
    }
    
    return 0;
}
