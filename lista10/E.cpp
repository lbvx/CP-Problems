#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p1 = 0, p2 = 0;
    int n, in;
    std::cin >> n;
    std::vector<int> cards(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> cards[i];
    }

    auto l = cards.begin(), r = cards.end() - 1;
    int* p = &p1;
    while (l <= r)
    {
        if (*l > *r)        
        {
            *p += *l;
            l++;
        }
        else
        {
            *p += *r;
            r--;
        }

        p = (p == &p1) ? &p2 : &p1;
    }

    std::cout << p1 << " " << p2 << "\n";    

    return 0;
}
