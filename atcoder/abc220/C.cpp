#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    int n;
    ull x;
    cin >> n;
    vector<ull> as(n);
    for (int i = 0; i < n; i++)
        cin >> as[i];
    cin >> x;

    ull sumAs = accumulate(as.begin(), as.end(), 0ULL);
    ull k = x / sumAs;
    ull sum = k * sumAs;
    k *= as.size();
    size_t i = 0;
    while (sum <= x)
    {
        sum += as[i];
        i++;
        k++;
    }

    cout << k << endl;    

    return 0;
}
