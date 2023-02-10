#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> pontos(N);
    for (int i = 0; i < N; i++)
        std::cin >> pontos[i];

    auto l = pontos.begin(), r = pontos.end() - 1;
    int soma = 0;
    std::string seq = "";
    for (int i = 0; i < N/2; i++)
    {
        int lsum = 0, rsum = 0;
        auto lt = l, rt = r;
        for (int j = 0; j < N/2-i; j++)
        {
            lsum += *lt;
            rsum += *rt;
            lt++; rt--;
        }

        if (lsum >= rsum)
        {
            soma += *l;
            seq += "L";
            l++;
        }
        else
        {
            soma += *r;
            seq += "R";
            r--;
        }

        // if (*l > *r)
        // {
        //     soma += *l;
        //     seq += "L";
        //     l++;
        // }
        // else if (*r > *l)
        // {
        //     soma += *r;
        //     seq += "R";
        //     r--;
        // }
        // else
        // {
        //     auto lt = l+1, rt = r-1;
        //     while (lt <= rt)
        //     {
        //         lt++;
        //         rt--;
        //     }
        //     if (*lt >= *rt)
        //     {
        //         soma += *l;
        //         seq += "L";
        //         l++;
        //     }
        //     else if (*rt > *lt)
        //     {
        //         soma += *r;
        //         seq += "R";
        //         r--;
        //     }

    }

    std::cout << soma << "\n";
    std::cout << seq << "\n";   

    return 0;
}
