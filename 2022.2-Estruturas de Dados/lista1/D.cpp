#include <iostream>
#include <vector>

// template <typename T>
// void printMatrix(std::vector<std::vector<T>> matrix)
// {
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix[i].size(); j++)
//         {
//             std::cout << matrix[i][j];
//         }
//         std::cout << std::endl;
//     }
// }

template <typename T>
bool isSymmetric(std::vector<std::vector<T>> matrix)
{
    int s = matrix.size();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (matrix[i][j] != matrix[s - i - 1][s - j - 1] || matrix[i][j] < 0L)
                return false;
        }
    }
    return true;
}

int main()
{
    int t, n;
    std::string in;
    std::cin >> t;
    std::vector<std::vector<long long>> matrix;

    for (int i = 0; i < t; i++)
    {
        std::cin >> in >> in;
        std::cin >> n;
        matrix = std::vector<std::vector<long long>>(n, std::vector<long long>(n));
        for (int j = 0; j < n*n; j++)
        {
            std::cin >> matrix[j / n][j % n];
        }
        std::cout << "Test #" + std::to_string(i+1) + ": "
                  << (isSymmetric(matrix) ? "Symmetric." : "Non-symmetric.")
                  << std::endl;
    }

    return 0;
}
