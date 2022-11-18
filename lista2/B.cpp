#include <iostream>
#include <vector>

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> v(h);
    for (int i = 0; i < h; i++)
        std::cin >> v[i];

    for (int i = 0; i < w + 2; i++)
        std::cout << '#';

    for (int i = 0; i < h; i++)
        std::cout << "\n#" << v[i] << '#';   

    std::cout << std::endl;
    for (int i = 0; i < w + 2; i++)
        std::cout << '#';
    std::cout << std::endl;
    
    return 0;
}