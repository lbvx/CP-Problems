#include <iostream>
#include <algorithm>
#include <vector>

class drug
{
	public:
	std::string name;
	int frequency;
	int taken;
    int priority;
	
	drug(std::string iname, int ifrequency, int ipriority)
	{
		name = iname;
		frequency = ifrequency;
        taken = ifrequency;
        priority = ipriority;
	}
	
	friend bool operator<(const drug &l, const drug &r)
	{
        if (l.taken == r.taken)
            return l.priority > r.priority;
		return l.taken > r.taken;
	}
};

int main()
{
	std::vector<drug> drugs;

    int t, n, k;

    std::cin >> t;
	while (t--)
    {
        std::make_heap(drugs.begin(), drugs.end());
        std::cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            std::string name;
            int freq;
            std::cin >> name >> freq;
            drugs.push_back(drug(name, freq, i));
            std::push_heap(drugs.begin(), drugs.end());
        }

        while (k--)
        {
            drug d = drugs.front();
            std::cout << d.taken << ' ' << d.name << '\n';

            std::pop_heap(drugs.begin(), drugs.end());
            drugs.pop_back();

            d.taken += d.frequency;
            drugs.push_back(d);
            std::push_heap(drugs.begin(), drugs.end());
        }

        drugs.clear();
    }
    std::make_heap(drugs.begin(), drugs.end());

    while (!drugs.empty())
    {
        std::cout << drugs.front().name << drugs.front().frequency << '\n';
        std::pop_heap(drugs.begin(), drugs.end());
        drugs.pop_back();
    }
	
	return 0;
}
