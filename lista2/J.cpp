#include <iostream>
#include <stack>

int main()
{
    int n;
    std::pair<int, int> v;
    std::stack<std::pair<int, int>> st;
    std::string in;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> in;
        if (in[1] == 'U') // PUSH
        {
            std::cin >> v.first;
            if (st.empty())
                v.second = v.first;
            else
                v.second = (st.top().second < v.first) ? st.top().second : v.first;
            st.push(v);
        }
        else if (in[1] == 'O') // POP
        {
            if (!st.empty())
                st.pop();
            else
                std::cout << "EMPTY\n";
        }
        else if (in[1] == 'I') // MIN
        {
            if (!st.empty())
                std::cout << st.top().second << '\n';
            else
                std::cout << "EMPTY\n";
        }
    }
    return 0;
}
