#include <iostream>
#include <vector>
#include <algorithm>

#define LIMITE 60

int main()
{
    std::vector<std::string> filenames;
    int n, rows, columns;
    std::string file;

    while(std::cin >> n)
    {
        filenames.clear();
        for (int i = 0; i < n; i++)
        {
            std::cin >> file;
            filenames.push_back(file);
        }
        std::sort(filenames.begin(), filenames.end());

        for (int i = 0; i < LIMITE; i++)
        {
            std::cout << "-";
        }
        std::cout << std::endl;

        columns = 2;
        rows = filenames.size() / columns;
        std::vector<int> largestInColumn(columns);

    }

    // for (int i = 0; i < n; i++)
    // {
    //     std::cout << filenames[i] << std::endl;
    // }

    return 0;
}
