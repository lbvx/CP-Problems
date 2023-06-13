// Magic Odd Square 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << "\n "[j == matrix[0].size() - 1 ? 0 : 1];
}

// função apenas pra testes da solução
bool verify(vector<vector<int>> &matrix)
{
    int sum;
    // linhas
    for (int i = 0; i < matrix.size(); i++)
    {
        sum = 0;
        sum = accumulate(matrix[i].begin(), matrix[i].end(), 0);
        if (!(sum & 1))
        {
            cout << "erro: linha " << i << endl;
            return false;
        }
    }

    // colunas
    for (int i = 0; i < matrix.size(); i++)
    {
        sum = 0;
        for (int j = 0; j < matrix.size(); j++)
            sum += matrix[j][i];

        if (!(sum & 1))
        {
            cout << "erro: coluna " << i << endl;
            return false;
        }
    }

    // diagonal principal
    sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        sum += matrix[i][i];
    }
    if (!(sum & 1))
    {
        cout << "erro: diagonal principal" << endl;
        return false;
    }

    // diagonal secundaria
    sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        sum += matrix[i][matrix.size() - 1 - i];
    }
    if (!(sum & 1))
    {
        cout << "erro: diagonal secundária" << endl;
        return false;
    }
    cout << "tudo ok" << endl;
    return true;
}

vector<vector<int>> oddSquare(int dim)
{
    vector<vector<int>> matrix(dim, vector<int>(dim));
    if (dim == 1)
    {
        matrix[0][0] = 1;
        return matrix;
    }

    vector<vector<int>> sub = oddSquare(dim - 2);
    for (int i = 0; i < sub.size(); i++)
    {
        for (int j = 0; j < sub[0].size(); j++)
        {
            matrix[i + 1][j + 1] = sub[i][j];
        }
    }

    int even = (dim - 2) * (dim - 2) + 1;
    int odd = (dim - 2) * (dim - 2) + 2;
    int evenCorners = dim / 2;
    
    // Pares
    for (int i = 0; i < evenCorners; i++)
    {
        matrix[0][i] = even;
        even += 2;
        matrix[matrix.size() - 1][i] = even;
        even += 2;
    }
    for (int i = 0; i < evenCorners; i++)
    {
        matrix[0][matrix.size() - 1 - i] = even;
        even += 2;
        matrix[matrix.size() - 1][matrix.size() - 1 - i] = even;
        even += 2;
    }

    // Impares
    matrix[0][matrix.size() / 2] = odd;
    odd += 2;
    matrix[matrix.size() - 1][matrix.size() / 2] = odd;
    odd += 2;

    for (int i = 1; i < matrix.size() - 1; i++)
    {
        matrix[i][0] = odd;
        odd += 2;
        matrix[i][matrix.size() - 1] = odd;
        odd += 2;
    }

    return matrix;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> res = oddSquare(n);
    printMatrix(res);
    // verify(res);
    
    return 0;
}
