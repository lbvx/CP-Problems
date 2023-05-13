// AtCoder Cards
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

set<char> atcoder{'a', 't', 'c', 'o', 'd', 'e', 'r'};

int main()
{
    multiset<char> s, t, eq;
    int atS, atT;
    string in;
    cin >> in;
    for (auto c : in)
    {
        if (c == '@')
            atS++;
        else
            s.insert(c);
    }
    cin >> in;
    for (auto c : in)
    {
        if (c == '@')
            atT++;
        else
            t.insert(c);
    }

    multiset<char> diff;
    // s - t
    set_difference(s.begin(), s.end(), t.begin(), t.end(), inserter(diff, diff.begin()));
    
    for (auto& d : diff)
    {
        // cout << d << ": ";
        // cout << (atcoder.find(d) != atcoder.end()) << ' ';
        if (atT == 0 || atcoder.find(d) == atcoder.end())
        {
            cout << "No" << endl;;
            return 0;
        }
        atT--;
    }
    // cout << endl;
    diff.clear();
    // t - s
    set_difference(t.begin(), t.end(), s.begin(), s.end(), inserter(diff, diff.begin()));
    for (auto& d : diff)
    {
        // cout << d << ": ";
        // cout << (atcoder.find(d) != atcoder.end()) << ' ';
        if (atS == 0 || atcoder.find(d) == atcoder.end())
        {
            cout << "No" << endl;;
            return 0;
        }
        atS--;
    }

    cout << "Yes" << endl;

    return 0;
}
