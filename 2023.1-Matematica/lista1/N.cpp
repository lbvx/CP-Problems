#include <bits/stdc++.h>

using namespace std;

map<long long, long long> sizeC;
long long seqSize(long long x)
{
    long long r;
    if (sizeC.find(x) != sizeC.end())
    {
        return sizeC[x];
    }
    else if (x & 1)
    {
        r = 1LL + seqSize(3LL*x + 1LL);
        sizeC[x] = r;
        return r;
    }
    else
    {
        r = 1LL + seqSize(x / 2LL);
        sizeC[x] = r;
        return r;
    }
}

int main()
{
    sizeC[1LL] = 0LL;
    int l, r;

    cin >> l >> r;
    while (l != 0 || r != 0)
    {
        if (l > r)
            swap(l, r);
        
        long long maiorSeq = 0LL;
        long long maiorX = 1LL;
        for (long long i = max(1, l); i <= r; i++)
        {
            long long nSeq;
            if (i == 1LL)
                nSeq = 3LL;
            else
                nSeq = seqSize(i);
            if (nSeq > maiorSeq)
            {
                maiorSeq = nSeq;
                maiorX = i;
            }
        }
        cout << "Between " << l << " and " << r
             << ", " << maiorX << " generates the longest sequence of "
             << maiorSeq << " values." << endl;

        cin >> l >> r;
    }

    return 0;
}
