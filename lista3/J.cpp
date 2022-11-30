#include <iostream>
#include <map>

class Person
{
    private:
        Person* parent1;
        Person* parent2;
    public:
        std::string name;
        std::string gene;

        Person() : name(""), gene(""), parent1(nullptr), parent2(nullptr) {}

        Person(std::string inName) : gene(""), parent1(nullptr), parent2(nullptr)
        {
            name = inName;
        }

        void addParent(Person* p)
        {
            if (parent1 == nullptr)
                parent1 = p;
            else
                parent2 = p;
        }

        bool geneIsKnown()
        {
            return gene != "";
        }

        bool findGene()
        {
            if (geneIsKnown())
                return false;
            
            if (!parent1->geneIsKnown())
            {
                parent1->findGene();
            }
            if (!parent2->geneIsKnown())
            {
                parent2->findGene();
            }

            if ((parent1->gene == "dominant" && parent2->gene == "dominant") || 
                (parent1->gene == "dominant" && parent2->gene == "recessive") ||
                (parent2->gene == "dominant" && parent1->gene == "recessive"))
            {
                gene = "dominant";
                return true;
            }
            if ((parent1->gene == "dominant" && parent2->gene == "non-existent") || 
                (parent1->gene == "non-existent" && parent2->gene == "dominant") ||
                (parent1->gene == "recessive" && parent2->gene == "recessive"))
            {
                gene = "recessive";
                return true;
            }
            gene = "non-existent";
            return true;
        }

        friend bool operator<(const Person& l, const Person& r)
        {
            return l.name < r.name;
        }

        friend bool operator==(const Person& l, const Person& r)
        {
            return l.name == r.name;
        }
};

int main()
{
    std::map<std::string, Person> s;
    int n;
    std::cin >> n;
    std::string name, cmd;
    Person p;

    while (n--)
    {
        std::cin >> name >> cmd;
        if (s.find(name) == s.end())
        {
            p = Person(name);
            s[name] = p;
        }

        if (cmd == "dominant" || cmd == "recessive" || cmd == "non-existent")
        {
            s[name].gene = cmd;
        }
        else
        {
            if (s.find(cmd) == s.end())
            {
                p = Person(cmd);
                s[cmd] = p;
            }
            s[cmd].addParent(&s[name]);
        }
    }

    for (auto &a : s)
    {
        a.second.findGene();
    }

    for (auto &a : s)
    {
        std::cout << a.second.name << " " << a.second.gene << std::endl;
    }

    return 0;
}
