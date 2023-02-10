#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::int8_t> subjects;
    int T, N, D, time;
    std::string name;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        while (N--)
        {
            std::cin >> name >> time;
            subjects[name] = time;
        }
        std::cin >> D >> name;
        std::cout << "Case " << i+1 << ": ";
        if (subjects.find(name) == subjects.end() || subjects[name] > D + 5)
            std::cout << "Do your own homework!\n";
        else if (subjects[name] > D)
            std::cout << "Late\n";
        else std::cout << "Yesss\n";
        subjects.clear();
    }
    return 0;
}
