#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> memo;
vector<int> kinds;
int inf = (1 << 30);

int solve(int t)
{
   if (t == 0)
      return 0;
   else if (t < 0)
      return inf;
   if (memo.count(t) > 0)
      return memo[t];

   int result = inf;
   for (int i = 0; i < kinds.size(); ++i)
   {
      result = min(result, solve(t - kinds[i]) + 1);
   }

   memo[t] = result;
   return result;
}

int main()
{
#ifndef SINGLE_FILE
   int kases;
   cin >> kases;
   for (int k = 0; k < kases; ++k)
   {
      memo.clear();
      kinds.clear();
#endif
      int n, t;
      cin >> n >> t;
      for (int i = 0; i < n; ++i)
      {
         int x;
         cin >> x;
         kinds.push_back(x);
      }

      int result = solve(t);
      if (result == inf)
      {
         cout << "Impossible." << endl;
      } else
      {
         cout << "Possible: " << result << endl;
      }
#ifndef SINGLE_FILE
   }
#endif
}
