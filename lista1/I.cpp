#include <iostream>
#include <vector>

// void printSquare(std::vector<std::vector<char>> square)
// {
//     for (int i = 0; i < square.size(); i++)
//     {
//         for (int j = 0; j < square.size(); j++)
//         {
//             std::cout << square[i][j];
//         }
//         std::cout << std::endl;
//     }
// }

bool compareSquares(std::vector<std::vector<char>> &s1, std::vector<std::vector<char>> &s2)
{
    for (int i = 0; i < s1.size(); i++)
        for (int j = 0; j < s1.size(); j++)
            if (s1[i][j] != s2[i][j])
                return false;
    
    return true;
}

void rotate90(std::vector<std::vector<char>> &square)
{
    std::vector<std::vector<char>> copy = square;
    for (int i = 0; i < square.size(); i++)
    {
        for (int j = 0; j < square.size(); j++)
        {
            square[j][square.size() - i - 1] = copy[i][j];
        }
    }
}

void mirrorVertically(std::vector<std::vector<char>> &square)
{
    std::vector<std::vector<char>> copy = square;
    for (int i = 0; i < square.size(); i++)
    {
        for (int j = 0; j < square.size(); j++)
        {
            square[square.size() - i - 1][j] = copy[i][j];
        }
    }
}

int main()
{
    std::vector<std::vector<char>> startSquare, endSquare;
    std::string in;

    int dim;
    int n = 0;
    while (std::cin >> dim)
    {
        n++;
        startSquare = std::vector<std::vector<char>>(dim, std::vector<char>(dim));
        endSquare = std::vector<std::vector<char>>(dim, std::vector<char>(dim));

        // leitura
        for (int i = 0; i < dim; i++)
        {
            std::cin >> in;
            for (int j = 0; j < dim; j++)
            {
                startSquare[i][j] = in[j];
            }
            std::cin >> in;
            for (int j = 0; j < dim; j++)
            {
                endSquare[i][j] = in[j];
            }
        }

        int totalRotation = 0;
        int mirrored = 0;
        bool finish = false;
        while (mirrored < 2)
        {
            while (totalRotation < 360)
            {
                if (compareSquares(startSquare, endSquare))
                {
                    finish = true;
                    break;
                }
                rotate90(startSquare);
                totalRotation += 90;
            }
            if (finish)
                break;
            mirrorVertically(startSquare);
            mirrored++;
            totalRotation = 0;
        }

        std::string out("Pattern " + std::to_string(n) + " was ");
        if (mirrored == 2)
            out += "improperly transformed";
        else if (mirrored == 1)
        {
            out += "reflected vertically";
            if (totalRotation > 0)
                out += " and ";
        }
        if (totalRotation > 0)
            out += "rotated " + std::to_string(totalRotation) + " degrees";
        
        if (totalRotation == 0 && mirrored == 0)
            out += "preserved";
        
        out += ".";
        std::cout << out << std::endl;
    }

    return 0;
}
