#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ano;
    string cmd;
    priority_queue<int, vector<int>, greater<int>> vinhos;
    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd[0] == '+')
        {
            cin >> ano;
            vinhos.push(ano);
        }
        else if (!vinhos.empty())
        {
            cout << vinhos.top() << endl;
            vinhos.pop();
        }
        else
            cout << -1 << endl;
    }
    return 0;
}