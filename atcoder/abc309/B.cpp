// Rotate
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void rotateClockwise(vector<string> &m)
{
    int last = m[0][0];
    int aux;
    // Primeira linha
    for (int i = 1; i < m.size(); i++)
    {
        aux = m[0][i];
        m[0][i] = last;
        last = aux;
    }
    // Ultima coluna
    for (int i = 1; i < m.size(); i++)
    {
        aux = m[i][m.size() - 1];
        m[i][m.size() - 1] = last;
        last = aux;
    }
    // Ultima linha
    for (int i = m.size() - 2; i >= 0; i--)
    {
        aux = m[m.size() - 1][i];
        m[m.size() - 1][i] = last;
        last = aux;
    }
    // Primeira coluna
    for (int i = m.size() - 2; i >= 0; i--)
    {
        aux = m[i][0];
        m[i][0] = last;
        last = aux;
    }
}

void printMatrix(vector<string> &m)
{
    for (int i = 0; i < m.size(); i++)
        cout << m[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
        cin >> matrix[i];

    rotateClockwise(matrix);
    printMatrix(matrix);

    return 0;
}
