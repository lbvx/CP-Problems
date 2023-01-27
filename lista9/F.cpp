#include <iostream>
#include <vector>
#include <queue>

struct city
{
    int population;
    int boxes;
    int ratio;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int nCities, boxes;
    std::cin >> nCities >> boxes;

    auto cmp = [](const city &l, const city &r) {return l.ratio < r.ratio;};

    while (nCities != -1)
    {
        std::vector<city> cities(nCities);
        for (int i = 0; i < nCities; i++)
        {
            std::cin >> cities[i].population;
            cities[i].boxes = 1;
            cities[i].ratio = cities[i].population;
        }
        std::priority_queue<city, std::vector<city>, decltype(cmp)> citiesPQ(cities.begin(), cities.end(), cmp);
        boxes -= nCities;
        while (boxes > 0)
        {
            city m = citiesPQ.top();
            citiesPQ.pop();
            m.boxes++;
            m.ratio = (m.population + m.boxes - 1) / m.boxes;
            citiesPQ.push(m);
            boxes--;
        }
        city m = citiesPQ.top();
        std::cout << m.ratio << '\n';

        std::cin >> nCities >> boxes;
    }
    
    return 0;
}
