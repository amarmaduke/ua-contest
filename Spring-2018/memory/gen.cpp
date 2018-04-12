#include <iostream>
#include <set>
#include <utility>
#include <random>

using namespace std;

typedef unsigned long long u64;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<u64> distribution_for_k(1000000LL, 10000000000LL);

    u64 n = 10000;
    u64 k = distribution_for_k(gen);
    cout << n << " " << k << endl;

    uniform_int_distribution<u64> d(1LL, k/2);

    for (int i = 0; i < n; ++i) {
        u64 t = d(gen);
        cout << ("a" + to_string(i)) << " " << t << endl;
    }
}