#include <bits/stdc++.h>

using namespace std;

long long solve(long long l, long long r)
{
    long long p = 1LL;
    while (p <= r)
    {
        p <<= 1;
    }
    p >>= 1;
    
    if (p == l)
    {
        return l ^ r;
    }
    else if (p > l)
    {
        return p ^ (p - 1LL);
    }
    else
    {
        return solve(l - p, r - p);
    }
}

int main()
{
    long long l, r;

    cin >> l >> r;

    cout << solve(l, r) << endl;

    return 0;
}
