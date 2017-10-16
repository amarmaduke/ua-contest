#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    cout << "26 1000" << endl;
    char f = 'a';
    for (int i = 0; i < 26; ++i) {
        cout << f << " 100 100" << endl;
        f += 1;
    }
    for (int i = 0; i < 1000; ++i) {
        cout << 100;
        bool previous = false;
        for (int j = 0; j < 100; ++j) {
            int test = rand() % 2;
            if (test == 0 || j == 0 || j == 99 || previous) {
                cout << " " << (char)('a' + (rand() % 26));
                previous = false;
            } else {
                cout << " ;";
                previous = true;
            }
        }
        cout << endl;
    }
}
