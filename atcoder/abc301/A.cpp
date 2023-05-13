// Overall Winner
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int t = count(s.begin(), s.end(), 'T');
    int a = s.size() - t;

    char w;
    if (t > a)
        w = 'T';
    else if (t < a)
        w = 'A';
    else
    {
        if (*(s.end() - 1) == 'T')
            w = 'A';
        else
            w = 'T';
    }

    cout << w << endl;

    return 0;
}
