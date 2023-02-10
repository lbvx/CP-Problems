#include <vector>
#include <string>
#include <iostream>

std::pair<int, int> getIndexOfClosest(std::vector<std::string> v, int index)
{
    std::pair<int, int> closest;

    // left
    int i = index;
    while (i >= 0 && v[i] == "?") i--;
    closest.first = i;

    // right
    i = index;
    while (i < v.size() && v[i] == "?") i++;
    closest.second = (i == v.size()) ? -1 : i;

    return closest;
}

int main()
{
    int n, q, st;
    std::cin >> n;
    std::vector<std::string> students(n);
    std::string pos;

    for (int i = 0; i < n; i++)
        std::cin >> students[i];

    std::pair<int, int> closest;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        std::cin >> st;
        st -= 1;
        closest = getIndexOfClosest(students, st);

        // std::cout << "esquerda: " << closest.first << " direita: " << closest.second << std::endl;

        int distL = st - closest.first;
        int distR = closest.second - st;
        if (distL == 0)
            pos = students[st];
        else if (distL == distR && closest.first != -1 && closest.second != -1)
            pos = "middle of " + students[closest.first] + " and " + students[closest.second];
        else if (distL < distR && closest.first != -1 || distR < 0)
        {
            pos = "";
            for (int i = 0; i < distL; i++)
                pos += "right of ";
            pos += students[closest.first];
        }
        else
        {
            pos = "";
            for (int i = 0; i < distR; i++)
                pos += "left of ";
            pos += students[closest.second];
        }

        std::cout << pos << std::endl;
    }

    return 0;
}
