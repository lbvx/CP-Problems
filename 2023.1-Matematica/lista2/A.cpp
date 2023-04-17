#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;

    while (cin >> n >> k)
    {
        int total = n;
        int butts = n;
        while (butts >= k)
        {
            butts = butts - k + 1;
            total++;
        }
        cout << total << '\n';
    }

    return 0;
}
