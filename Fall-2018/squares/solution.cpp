#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    cout << (n * (n + 1) * ((2 * n) + 1)) / 6 << "\n";
    
    // alternate solution that we're more likely to see
    // long long result;
    // for (int i = 1; i <= n; ++i) result += i * i;
    // cout << result << "\n";

    return 0;
}
