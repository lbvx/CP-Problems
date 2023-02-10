#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> m >> n;
    std::vector<int> valores(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> valores[i];
    }

    int total = 0;
    int emprestimo = 0;

    for (const auto &v : valores)
    {
        total += v;
        if (total < 0)
        {
            emprestimo += -total;
            total = 0;
        }
    }

    if (emprestimo > m)
        std::cout << -1 << "\n";
    else
        std::cout << emprestimo << "\n";

    return 0;
}
