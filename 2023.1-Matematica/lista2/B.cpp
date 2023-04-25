#include <bits/stdc++.h>

using namespace std;

int main()
{
    int numer, denom;
    while (cin >> numer >> denom)
    {
        vector<int> res;
        int n = 0;

        while (denom != 0)
        {
            n = numer / denom;
            res.push_back(n);
            numer -= n * denom;
            swap(numer, denom);
        }

        cout << '[' << res[0];
        if (res.size() > 1)
            cout << ';';
        for (int i = 1; i < res.size() - 1; i++)
        {
            cout << res[i] << ',';
        }
        if (res.size() > 1)
            cout << res.back();
        cout << ']' << endl;
    }
    return 0;
}
