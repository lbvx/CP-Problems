#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;
    set<pair<int, string>> donors;

    while (N--)
    {
        int age;
        string bt;
        cin >> age >> bt;
        donors.emplace(age, bt);
    }

    cout << donors.size() << '\n';

    return 0;
}
