#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int n, t_n;
    cin >> n >> t_n;
    assert(n <= 100 && n > 0);
    assert(t_n <= 1000 && t_n > 0);

    for (int i = 0; i < 2*n; ++i)
    {
        int x;
        cin >> x;
        assert(x >= -10 && x <= 10);
    }

    int m, t_m;
    cin >> m >> t_m;
    assert(m <= 100 && m > 0);
    assert(t_m <= 1000 && t_m > 0);
    
    for (int i = 0; i < 2*m; ++i)
    {
        int x;
        cin >> x;
        assert(x >= -10 && x <= 10);
    }

    int q;
    cin >> q;
    assert(q <= 10000 && q > 0);

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        assert(l >= 0);
        assert(r >= 0);
        assert(l <= r);
    }
}