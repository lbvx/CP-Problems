#include <bits/stdc++.h>

using namespace std;

string base3(int x)
{
    string res = "";
    if (x == 0)
        res = "0";
    while (x > 0)
    {
        int rem = x % 3;
        x /= 3;

        res = to_string(rem) + res; 
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n >= 0)
    {
        cout << base3(n) << endl;

        cin >> n;
    }

    return 0;
}
