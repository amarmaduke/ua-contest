#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));

    int n = (rand() % (1000 - 3)) + 3;
    int center = (rand() % n) + 1;

    vector<pair<int, int> > edges;

    for (int i = 0; i < n; ++i)
    {
        if (i + 1 != center)
        {
            edges.push_back({i+1, center});
        }
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(edges.begin(), edges.end(), g);

    cout << n << " " << edges.size() << endl;
    for (auto& p : edges)
    {
        if (rand() % 2 == 0)
            cout << p.first << " " << p.second << endl;
        else
            cout << p.second << " " << p.first << endl;
    }
}