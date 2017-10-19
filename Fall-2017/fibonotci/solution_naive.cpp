#include <iostream>

using namespace std;

typedef long long i64;

int main() {
    i64 q;
    i64 m = 7001;
    cin >> q;

    for (int j = 0; j < q; ++j) {
        i64 n, c1, c2, a, b;
        cin >> n >> c1 >> c2 >> a >> b;

        i64 fp = a;
        i64 fpp = b;
        i64 f = 0;
        for (int i = 3; i <= n; ++i) {
            f = (c1*fp % m + c2*fpp % m) % m;
            fpp = fp;
            fp = f;
        }

        cout << f << endl;
    }
}