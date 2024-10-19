// osu!mania
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printReverseVector(vector<int> v) {
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;
}

#define MULTIPLE
void solve() {
    int n;
    cin >> n;

    vector<int> order;
    string line;

    while(n--) {
        cin >> line;
        order.push_back(line.find('#') + 1);
    }
    printReverseVector(order);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    #ifdef MULTIPLE
    cin >> t;
    #endif

    for (int i = 0; i < t; i++)
        solve();
    
    return 0;
}
