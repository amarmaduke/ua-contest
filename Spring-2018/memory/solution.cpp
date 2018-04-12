#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long i64;

int main()
{
    i64 n, k;
    cin >> n >> k;

    vector<i64> times;
    for (i64 i = 0; i < n; ++i)
    {
        string s;
        i64 t;
        cin >> s >> t;
        times.push_back(t);
    }

    sort(times.begin(), times.end());

    i64 result = 0;
    for (i64 i = 0; i < n; ++i)
    {
        if (k - times[i] >= 0)
        {
            result += 1;
            k -= times[i];
        }
        else { break; }
    }

    cout << result << endl;
}