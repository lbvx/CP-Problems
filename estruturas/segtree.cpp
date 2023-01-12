#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
#include <algorithm>

template<typename T>
class SegmentTree
{
    int N;
    std::vector<T> ns;

public:
    SegmentTree(const std::vector<T>& xs) : N(xs.size()), ns(2*N, 0)
    {
        std::copy(xs.begin(), xs.end(), ns.begin() + N);

        for (int i = N - 1; i > 0; --i)
            ns[i] = ns[2*i] + ns[2*i + 1];
    }

    T RSQ(int i, int j)
    {
        // As folhas estão na segunda metade de ns
        int a = i + N, b = j + N;
        T s = 0;

        while (a <= b)
        {
            if (a & 1)                  
                s += ns[a++];

            if (not (b & 1))
                s += ns[b--];

            a /= 2;
            b /= 2;
        }

        return s;
    }

    void update(int i, T value)
    {
        int a = i + N;

        ns[a] += value;

        // Atualiza todos os pais de a
        while (a >>= 1)
            ns[a] = ns[2*a] + ns[2*a + 1];
    }
};

template<typename T>
class SegmentTree_LAZY
{
private:
    int N;
    std::vector<T> ns, lazy;

public:
    SegmentTree(const std::vector<int>& xs)
        : N(xs.size()), ns(4*N, 0), lazy(4*N, 0)
    {
        for (size_t i = 0; i < xs.size(); ++i)
            update(i, i, xs[i]);
    }

    void update(int a, int b, T value)
    {
        update(1, 0, N - 1, a, b, value);
    }

private:
    void update(int node, int L, int R, int a, int b, T value) {
        // Lazy propagation
        if (lazy[node])
        {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R)      // Se o nó não é uma folha, propaga
            {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        // [a, b] ∩ [L, R] = {∅}
        if (a > R or b < L)
            return;

        // [L, R] ⊂ [a, b] está contido; é subconjunto de
        if (a <= L and R <= b)
        {
            ns[node] += (R - L + 1) * value;

            if (L < R)
            {
                lazy[2*node] += value;
                lazy[2*node + 1] += value;
            }

            return;
        }
 
        update(2*node, L, (L + R)/2, a, b, value);
        update(2*node + 1, (L + R)/2 + 1, R, a, b, value);

        ns[node] = ns[2*node] + ns[2*node + 1];
    } 

public:
    T RSQ(int a, int b)
    {
        return RSQ(1, 0, N - 1, a, b);
    }

private:
    T RSQ(int node, int L, int R, int a, int b)
    {
        if (lazy[node])
        {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R) {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (a > R or b < L)
            return 0;

        if (a <= L and R <= b)
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x + y;
    }
};

template<typename T>
class SegmentTree_TOPDOWN
{
    int N;
    std::vector<T> ns;

public:
    SegmentTree(const std::vector<int>& xs) : N(xs.size()), ns(4*N, 0)
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
        
        ns[node] += value;

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
            return 0;

        if (a <= L and R <= b)      // [L, R] ⊂ [a, b] 
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x + y;
    }

};

#endif
