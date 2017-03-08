#include <iostream>
#include <cassert>
#include <set>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    assert(n <= 100 && n >= 1);
    assert(m <= (n*(n-1))/2 && m >= 1);

    string f;
    cin >> f;
    int s = f.size();

    for (int j = 0; j < s; ++j)
    {
        assert(f[j] == '0' || f[j] == '1');
    }

    for (int i = 1; i < n; ++i)
    {
        string x;
        cin >> x;
        assert(x.size() == s);

        for (int j = 0; j < s; ++j)
        {
            assert(x[j] == '0' || x[j] == '1');
        }
    }

    set<pair<int, int> > edges;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        assert(a < n && a >= 0);
        assert(b < n && b >= 0);
        assert(a != b);
        assert(edges.count(make_pair(a, b)) == 0);
        assert(edges.count(make_pair(b, a)) == 0);

        edges.insert(make_pair(a, b));
    }

    int last;
    cin >> last;
    assert(last < n && last >= 0);
}