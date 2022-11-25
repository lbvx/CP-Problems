#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    map<char, int> letras;
    
    cin >> in;
    for (auto c : in)
    {
        letras[c]++;
    }
    for (auto e : letras)
    {
        cout << e.first << ": " << e.second << endl;
    }
    return 0;
}