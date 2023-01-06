#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::priority_queue<int> snake;
    int in;
    while (n--)
    {
        std::cin >> in;
        snake.push(in);
    }
    int l = 0;
    while (k--)
    {
        l += snake.top();
        snake.pop();
    }
    std::cout << l << '\n';
    return 0;
}
