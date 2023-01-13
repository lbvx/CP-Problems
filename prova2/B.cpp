#include <bits/stdc++.h>

using namespace std;

int factorial(int x)
{
    int p = 1;
    while (x > 0)
    {
        p *= x;
        x--;
    } 
    return p;
}

int nck (int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, R;
    cin >> N >> R;
    
    cout << nck(N, 2) - R << '\n';
    
    return 0;
}
