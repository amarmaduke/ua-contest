#include <iostream>

using namespace std;

typedef unsigned long long u64;

u64 memo[100001];
u64 mod = 10000014;

u64 catalan(u64 n)
{
    if (n == 0) return 1;
    if (memo[n] != 0) return memo[n];
    u64 result = 0;
    for (int i = 1; i <= n; ++i)
        result += (catalan(i-1)*catalan(n-i))%mod;
    memo[n] = result%mod;
    return result%mod;
}

int main()
{
    u64 n;
    cin >> n;
    cout << catalan(n) << endl;
}
