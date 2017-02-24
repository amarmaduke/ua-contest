#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    set<char> forbidden;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        forbidden.insert(c);
    }

    int pos = 1;

    for (char f0 = 'a'; f0 <= 'z'; ++f0)
    {
        for (char f1 = 'a'; f1 <= 'z'; ++f1)
        {
            for (char f2 = 'a'; f2 <= 'z'; ++f2)
            {
                for (char f3 = 'a'; f3 <= 'z'; ++f3)
                {
                    int c0 = forbidden.count(f0);
                    int c1 = forbidden.count(f1);
                    int c2 = forbidden.count(f2);
                    int c3 = forbidden.count(f3);
                    int c = c0 + c1 + c2 + c3;

                    if (c <= 0)
                    {
                        if (pos >= m && pos < m + k)
                            cout << f0 << f1 << f2 << f3 << endl;
                        pos++;
                    }
                }
            }
        }
    }
}