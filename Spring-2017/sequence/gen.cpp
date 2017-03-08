#include <iostream>

using namespace std;

int main()
{
    srand(time(0));
    int n = rand() % 100, t_n = rand() % 1000;
    int m = rand() % 100, t_m = rand() % 1000;
    int q = rand() % 10000;

    cout << n << " " << t_n << endl;
    for (int i = 0; i < 2*n; ++i)
    {
        int x = (rand() % 21) - 10;
        if (i == 0)
        {
            cout << x;
        }
        else
        {
            cout << " " << x;
        }
    }
    cout << endl;

    cout << m << " " << t_m << endl;
    for (int i = 0; i < 2*m; ++i)
    {
        int x = (rand() % 21) - 10;
        if (i == 0)
        {
            cout << x;
        }
        else
        {
            cout << " " << x;
        }
    }
    cout << endl;

    cout << q << endl;
    for (int i = 0; i < q; ++i)
    {
        int l = rand() % max(t_n, t_m);
        int r = l + (rand() % (max(t_n, t_m) - l));
        cout << l << " " << r << endl;
    }
}