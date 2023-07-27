#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    int t, b, n;
    cin >> t;

    for (int ti = 1; ti <= t; ti++)
    {
        cin >> b >> n;
        int pontuacao = 0;
        if (n >= 3)
        {
            pontuacao = b;
            pontuacao += 100 * (n - 3);
        }
        if (n > 7)
        {
            pontuacao = pontuacao * 3 / 2;
        }
        else if (n > 3)
        {
            pontuacao = pontuacao * 5 / 4;
        }
        cout << "Caso " << ti << ": " << pontuacao << " ponto" << (pontuacao == 1 ? "" : "s") << endl;
    }
    
    return 0;
}