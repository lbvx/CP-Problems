#include <bits/stdc++.h>

using namespace std;

long long f(const long long X, const vector<long long> &as)
{
    long long res = 0;
    for (auto &a : as)
    {
        res += (X ^ a);
    }
    return res;
}

int main()
{
    int N;
    long long K, X = 0LL;

    cin >> N >> K;
    vector<long long> as(N);
    for(int i = 0; i < N; i++)
    {
        cin >> as[i];
    }
    
    for (int i = 62; i >= 0; i--)
    {
        int ones = 0, zeros = 0;
        for (auto &a : as)
        {
            if (a & (1LL << i))
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }
        if (zeros > ones && (X | (1LL << i)) <= K)
        {
            X |= (1LL << i);
        }
    }

    cout << f(X, as) << '\n';

    return 0;
}
