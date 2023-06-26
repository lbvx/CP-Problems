// BowWow and the Timetable   
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int count = s.size() / 2;
    if (s.size() % 2 == 1 && s.find('1', 1) != string::npos)
        count++;
    cout << count << endl;
    
    return 0;
}
