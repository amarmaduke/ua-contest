#include <iostream>
#include <cassert>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    assert(n >= 1 && n <= 26);
    assert(q >= 1 && q <= 1000);

    map<char, pair<int, int> > functions;
    for (int i = 0; i < n; ++i) {
        char x;
        int a, b;
        cin >> x >> a >> b;

        assert(functions.count(x) == 0);
        assert(a >= 1 && a <= 100);
        assert(b >= 1 && b <= 100);
        assert(x >= 'a' && x <= 'z');
        functions[x] = make_pair(a, b);
    }

    for (int i = 0; i < q; ++i) {
        int count;
        cin >> count;
        assert(count >= 1 && count <= 100);
        for (int j = 0; j < count; ++j) {
            char x;
            cin >> x;
            assert((x >= 'a' && x <= 'z') || x == ';');
            if (x >= 'a' && x <= 'z') {
                assert(functions.count(x) == 1);
            }
        }
    }
}