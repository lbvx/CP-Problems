#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<char> moldes;
    string frase;
    int n;
    cin >> n;
    while (n--)
    {
        moldes = set<char>();
        cin >> frase;
        for (auto c : frase)
            moldes.insert(c);

        cout << moldes.size() << endl;
    }
    return 0;
}
