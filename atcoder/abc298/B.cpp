#include <bits/stdc++.h>

using namespace std;

void rotate90(std::vector<std::vector<int>> &m)
{
    std::vector<std::vector<int>> copy = m;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            m[j][m.size() - i - 1] = copy[i][j];
        }
    }
}

bool check(vector<vector<int>>& A, vector<vector<int>>& B)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N)),
                        B(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    int rotations = 0;
    while (rotations < 4)
    {
        if (check(A, B))
            break;
        rotate90(A);
        rotations++;
    }

    if (rotations == 4)
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}
