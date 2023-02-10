#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string in;
    std::cin >> in;
    for (auto l = in.begin(), r = in.end()-1; l < r; l++, r--)   
    {
        if (*l != *r)
        {
            std::cout << "No\n";
            return 0;
        }
    }
    
    std::cout << "Yes\n";
    return 0;
}
