#include <iostream>
#include <map>

using namespace std;

int score[101];
int cost[101];

map<int, int> memo;

int solve(int life, int n) {
   if (life <= 0)
      return 0;
   if (memo.count(life) > 0)
      return memo[life];

   int m = 0;
   for (int i = 0; i < n; ++i) {
      int temp = solve(life - cost[i], n) + score[i];
      m = max(m, temp);
   }

   memo[life] = m;
   return m;
}

int main() {

//   while (true) {
      int n;
      cin >> n;
//      if (n == 0) break;
//      memo.clear();

      int lifetime, bonus;
      cin >> lifetime >> bonus;

      for (int i = 0; i < n; ++i) {
         int x;
         cin >> x;
         score[i] = x;
      }

      bool inf = false;
      for (int i = 0; i < n; ++i) {
         int x;
         cin >> x;
         cost[i] = x - bonus;
         if (x <= bonus && score[i] > 0) inf = true;
      }

      if (!inf) {
         cout << solve(lifetime, n) << endl;
      } else {
         cout << "Infinite." << endl;
      }
//   }
}
