#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main()
{
    srand(time(0));

    int n = rand() % 100, m = rand() % (n*(n-1)/2);
    cout << n << " " << m << endl;
    int s = (rand() % 10) + 1;

    for (int i = 0; i < n; ++ i)
    {
        for (int j = 0; j < s; ++j)
        {
            int x = rand() % 2;
            cout << x;
        }
        cout << endl;
    }

    set<pair<int, int> > edges;
    while (edges.size() != m)
    {
        int a = rand() % n, b = rand() % n;
        pair<int, int> p = make_pair(a, b);
        pair<int, int> t = make_pair(b ,a);
        if (a == b || edges.count(t) > 0) continue;
        edges.insert(p);
    }

    for (set<pair<int, int> >::iterator iter = edges.begin(); iter != edges.end(); ++iter)
    {
        pair<int, int> p = *iter;
        cout << p.first << " " << p.second << endl;
    }

    int f = rand() % n;
    cout << f << endl;
}