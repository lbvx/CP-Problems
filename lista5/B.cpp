#include <iostream>
#include <vector>
#include <set>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> buttons(n+1);
    std::set<int> l;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> buttons[i];
    }

    int lighten = 1;
    while (true)
    {
        if (lighten == 2)
        {
            std::cout << l.size() << '\n';
            return 0;
        }
        else if (l.find(lighten) != l.end())
        {
            std::cout << "-1" << '\n';
            return 0;
        }
        l.insert(lighten);
        lighten = buttons[lighten];
    }
}
