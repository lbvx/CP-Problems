// Maximum GCD
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b > a)
        swap(a, b);

    ll r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    while (n--)
    {
        vector<ll> xs;
        getline(cin, line);
        stringstream lineStream(line);
        ll x;
        while (lineStream >> x)
            xs.push_back(x);

        ll maxGCD = 0;
        for (int i = 0; i < xs.size(); i++)
            for (int j = i + 1; j < xs.size(); j++)
                maxGCD = max(maxGCD, gcd(xs[i], xs[j]));

        cout << maxGCD << endl;
    }    
    return 0;
}
