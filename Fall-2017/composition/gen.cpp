#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    srand(time(0));
    int n = (rand() % 25) + 1;
    int q = (rand() % 700) + 200;
    cout << n << " " << q << endl;

    for (int i = 0; i < n; ++i) {
        int a = (rand() % 99) + 1;
        int b = (rand() % 99) + 1;
        cout << (char)('a' + i) << " " << a << " " << b << endl;
    }

    for (int i = 0; i < q; ++i) {
        int x = (rand() % 98) + 1;
        cout << x;
        bool previous = false;
        for (int j = 0; j < x; ++j) {
            int test = rand() % 2;
            if (test == 0 || j == 0 || j == x - 1 || previous) {
                cout << " " << (char)('a' + (rand() % n));
                previous = false;
            } else {
                cout << " ;";
                previous = true;
            }
        }
        cout << endl;
    }
}
