#include <iostream>
#include <cassert>

using namespace std;

typedef long long i64;

int main() {
    i64 q;
    cin >> q;
    assert(q > 0 && q <= 1000);
    
    for (int i = 0; i < q; ++i) {
        int n, c1, c2, a, b;
        cin >> n >> c1 >> c2 >> a >> b;
        assert(n > 2 && n <= 100000000);
        assert(c1 > 0 && c1 <= 7000);
        assert(c2 > 0 && c2 <= 7000);
        assert(a > 0 && a <= 7000);
        assert(b > 0 && b <= 7000);
    }
}