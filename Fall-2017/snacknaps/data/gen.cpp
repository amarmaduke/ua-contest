#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int n = 3000, m = 3000, c_lim = 3000, g_lim = 100000;

int main() {
    srand(time(NULL));
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ((rand() % c_lim)+ 1) << " " << ((rand() % g_lim) + 1) << "\n";
    }
}