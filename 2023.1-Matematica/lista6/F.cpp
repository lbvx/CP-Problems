// Goldbach's Conjecture
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool prime(ll x)
{
    if (x % 2 == 0)
        return false;
    for (ll i = 3; i*i <= x; i += 2LL)
        if (x % i == 0)
            return false;
    return true;
}

ll nextPrime(ll x)
{
    if (x == 2 || x == 1)
        return 2;
    if (x % 2 == 0)
        x++;
    while (true)
    {
        if (prime(x))
            return x;
        x += 2;
    }
}

ll previousPrime(ll x)
{
    if (x <= 2)
        return 2;
    if (x % 2 == 0)
        x--;
    while (true)
    {
        if (prime(x))
            return x;
        x -= 2;
    }
}

int main()
{
    ll n;
    cin >> n;
    ll x, y;

    while (n != 0)
    {
        x = 2;
        y = previousPrime(n);

        while (x < y)
        {
            if (x + y == n)
                break;

            if (x + y > n)
                y = previousPrime(y - 1);

            else if (x + y < n)
                x = nextPrime(x + 1);
        }

        if (x + y == n)
            cout << n << " = " << x << " + " << y << endl;
        else
            cout << "Goldbach's conjecture is wrong." << endl;
        
        cin >> n;
    }
    return 0;
}
