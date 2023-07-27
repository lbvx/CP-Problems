#include <bits/stdc++.h>
#include <climits>

using ll = long long;
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int pacote;
    int minRem = INT_MAX;
    int melhorPac = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> pacote;
        if (pacote % m < minRem)
        {
            minRem = pacote % m;
            melhorPac = pacote;
        }
        else if (pacote % m == minRem && pacote > melhorPac)
        {
            melhorPac = pacote;
        }
    }
    cout << melhorPac << endl;
    
    return 0;
}