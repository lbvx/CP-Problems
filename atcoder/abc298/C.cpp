#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;

    cin >> N >> Q;
    vector<multiset<int>> boxes(N+1, multiset<int>());

    map<int, set<int>> cards;

    while (Q--)
    {
        int com, i, j;
        cin >> com;

        if (com == 1)
        {
            cin >> i >> j;
            boxes[j].insert(i);
            cards[i].insert(j);
        }
        else if (com == 2)
        {
            cin >> j;
            for (auto& c : boxes[j])
            {
                cout << c << ' ';
            }
            cout << '\n';
        }
        else
        {
            cin >> i;
            for (auto& b : cards[i])
                cout << b << ' ';
            cout << '\n';
        }
    }

    return 0;
}
