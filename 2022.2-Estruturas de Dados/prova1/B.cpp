#include <bits/stdc++.h>

using namespace std;

int main()
{
    string card;
    int sum = 0;
    int value;
    do
    {
        cin >> card;
        switch (card[0])
        {
            case 'A':
             value = 1;
             break;
            case 'T':
            case 'J':
            case 'Q':
            case 'K':
             value = 10;
             break;
            default:
             value = atoi(&card[0]);
        }
        sum += value;
    }  while (sum <= 21);
    sum -= value;
    cout << sum << endl;
    return 0;
}