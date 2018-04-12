#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> counts(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        counts[a-1] += 1;
        counts[b-1] += 1;
    }

    int nonones = count(counts.begin(), counts.end(), 1);
    if (nonones + 1 == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}