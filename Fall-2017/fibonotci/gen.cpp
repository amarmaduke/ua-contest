#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    int q = (rand() % 100) + 1;
    cout << q << endl;
    for (int i = 0; i < q; ++i) {
        int n = (rand() % 100000000) + 3;
        int c1 = (rand() % 1000) + 1;
        int c2 = (rand() % 1000) + 1;
        int a = (rand() % 1000) + 1;
        int b = (rand() % 1000) + 1;
        cout << n << " " << c1 << " " << c2 << " " << a << " " << b << endl;
    }
}