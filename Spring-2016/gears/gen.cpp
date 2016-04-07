#include <iostream>
#include <set>

using namespace std;

// cat <<< "n t" | ./gen >> input

int main()
{
   int n, t;
   cin >> n >> t;
   cout << n << " " << t << endl;
   set<int> used;
   for (int i = 0; i < n; ++i)
   {
      int x = (rand() % (t - 1)) + 1;
      while (used.count(x) > 0)
         x = (rand() % (t - 1)) + 1;
      used.insert(x);
      cout << x;
      if (i + 1 != n)
         cout << " ";
   }
   cout << endl;
}
