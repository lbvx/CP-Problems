#include <bits/stdc++.h>

using namespace std;

void come(char cupim, const vector<int> &massas, vector<int> &tamanduas, int capacidade)
{
    int m;
    if (cupim == 'F')
        m = massas[0];
    else if (cupim == 'A')
        m = massas[1];
    else
        m = massas[2];

    int i = 0;
    while (true)
    {
        if (tamanduas[i] - m >= 0)
        {
            tamanduas[i] -= m;
            return;
        }
        else if (i == tamanduas.size() - 1)
        {
            tamanduas.push_back(capacidade);
            tamanduas[i+1] -= m;
            return;
        }
        i++;
    }
}

int main()
{
    vector<int> massaCupins(3);
    int capacidade, nCupins;
    string in;
    cin >> massaCupins[0] >> massaCupins[1] >> massaCupins[2];
    cin >> capacidade >> nCupins;
    queue<int> cupins;
    vector<int> tamanduas(1, capacidade);

    cin >> in;
    for (char c : in)
    {
        come(c, massaCupins, tamanduas, capacidade);
    }

    cout << tamanduas.size() << endl;

    return 0;
}