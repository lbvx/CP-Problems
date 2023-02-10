#include <iostream>
#include <set>
#include <algorithm>

void eraseSymbols(std::string &s)
{
    s.erase(std::remove_if(s.begin(), s.end(),
            []( char const &c ) -> bool { return !std::isalpha(c) && c != '-'; }),
            s.end());
}

int main()
{
    std::set<std::string> words;
    std::string in, p;
    while (std::cin >> in)
    {
        while (*(in.end() - 1) == '-')
        {
            in.erase(in.end() - 1);
            std::cin >> p;
            in += p;
        }

        std::transform(in.begin(), in.end(), in.begin(), ::tolower);
        eraseSymbols(in);
        words.insert(in);
    }
    for (auto e : words)
        std::cout << e << std::endl;
    return 0;
}
