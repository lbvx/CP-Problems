#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

std::set<char> sep{'(', ')', ',', '.', ':', ';', '!', '?', '\"'};

void eraseSymbols(std::string &s)
{
    s.erase(std::remove_if(s.begin(), s.end(),
            []( char const &c ) -> bool 
                { return sep.find(c) != sep.end();
            }),
            s.end());
}

int main()
{
    std::multiset<std::string> totalWords;
    std::set<std::string> uniqueWords;
    std::string in;
    int lambda, n;
    double entropy, entropyMax, entropyRel;

    std::cout << std::fixed << std::setprecision(1);

    std::cin >> in;
    while (in != "****END_OF_INPUT****")
    {
        if (in == "****END_OF_TEXT****")
        {
            lambda = totalWords.size();
            n = uniqueWords.size();
            double sum = 0.0;
            for (auto w : uniqueWords)
            {
                int pi = totalWords.count(w);
                sum += pi * (log10(lambda) - log10(pi));
            }

            entropy = sum / lambda;
            entropyMax = log10(lambda);
            entropyRel = entropy / entropyMax * 100.0;
            std::cout << lambda << " "
                      << round(entropy * 10.0) / 10.0 << " "
                      << (int) round(entropyRel) << "\n";

            totalWords.clear();
            uniqueWords.clear();
        }
        else
        {
            eraseSymbols(in);
            std::transform(in.begin(), in.end(), in.begin(), ::tolower);
            totalWords.insert(in);
            uniqueWords.insert(in);
        }
        std::cin >> in;
    }

    return 0;
}
