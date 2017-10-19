#include <iostream>

using namespace std;

int main() {
    cout << "1000" << endl;
    int c1 = 7000, c2 = 7000, a = 7000, b = 7000;
    for (int i = 0; i < 1000; ++i) {
        cout << "100000000" << " " << c1 << " " << c2 << " " << a << " " << b << endl;
        switch (i % 4) {
            case 0:
                --c1;
                break;
            case 1:
                --c2;
                break;
            case 2:
                --a;
                break;
            case 3:
                --b;
                break;
        }
    }
}