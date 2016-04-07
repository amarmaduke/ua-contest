#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> memo;
vector<int> kinds;
int inf = (1 << 30);

int solve(int t)
{
   int large_count = 0;
   if (t == 0)
      return 0;
   else if (t < 0)
      return inf;
   for (int i = 0; i < kinds.size(); ++i)
   {
      if (kinds[i] == t)
         return 1;
      if (kinds[i] > t)
         ++large_count;
   }
   if (large_count == kinds.size())
      return inf;
   if (memo[t])
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
   int kases;
   cin >> kases;
   for (int k = 0; k < kases; ++k)
   {
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
   }
}
