#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <random>

using namespace std;

int main()
{
    srand(time(0));

    int n = (rand() % (1000 - 3)) + 3;
    int e = (rand() % (1000*1000 - 2)) + 2;

    map<pair<int, int>, int> edges;

    for (int i = 0; i < n - 1; ++i)
    {
        edges[{i+1, i+2}] = 1;
    }

    for (int i = 0; i < e; ++i)
    {
        int a = (rand() % n) + 1;
        int b = (rand() % n) + 1;
        int m = min(a, b);
        int M = max(a, b);

        if (a != b)
        {
            edges[{m, M}] = 1;
        }
    }

    cout << n << " " << edges.size() << endl;
    for (auto& p : edges)
    {
        int a = p.first.first;
        int b = p.first.second;

        if (rand() % 2 == 0) {
            cout << a << " " << b << endl;
        } else {
            cout << b << " " << a << endl;
        }
    }
}