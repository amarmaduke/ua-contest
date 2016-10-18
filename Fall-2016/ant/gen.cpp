#include <cstdlib>
#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include <ctime>

using namespace std;

bool dft(map<int, map<int, int> >& grid, int n) {
   map<int, bool> visited;
   stack<int> s;

   s.push(0);

   while (s.size() > 0) {
      int current = s.top();
      visited[current] = true;
      s.pop();

      for (int i = 0; i < n; ++i) {
         if (i != current && !visited[i] && grid[i][current] > 0) {
            s.push(i);
         }
      }
   }

   bool result = true;

   for (int i = 0; i < n; ++i) {
      result &= visited[i];
   }

   return result;
}

int main() {
   srand(time(0));

   for (int i = 0; i < 10; ++i) {
      int n = (rand() % 399) + 1;
      if (i > 6) n = 400;
      int a = (rand() % min(9, n)) + 1;
      int l = (rand() % min(9, n)) + 1;
      int e = (rand() % (n-2)) + 1;

      map<int, map<int, int> > grid;

      set<int> ants, larva;

      while (ants.size() != a) {
         ants.insert(rand() % n);
      }

      while (larva.size() != l) {
         larva.insert(rand() % n);
      }

      while (!dft(grid, n)) {
         for (int i = 0; i < 10; ++i) {
            int u = rand() % n;
            int v = rand() % n;
            int c = (rand() % 1000) + 1;

            if (u != v) {
               grid[u][v] = c;
               grid[v][u] = c;
            }
         }
      }

      vector<tuple<int, int, int>> edges;
      set<tuple<int, int>> seen;
      for (auto i : grid) {
         for (auto j : i.second) {
            auto pair1 = tie(i.first, j.first);
            auto pair2 = tie(j.first, i.first);
            auto trip = tie(i.first, j.first, j.second);
            if (seen.count(pair1) == 0 && j.second != 0) {
               seen.insert(pair1);
               seen.insert(pair2);
               edges.push_back(trip);
            }
         }
      }

      cout << n << " " << edges.size() << endl;
      cout << a << " " << l << " " << e << endl;

      cout << *ants.begin();
      for (auto x = ++ants.begin(); x != ants.end(); ++x) {
         cout << " " << *x;
      }
      cout << endl;

      cout << *larva.begin();
      for (auto x = ++larva.begin(); x != larva.end(); ++x) {
         cout << " " << *x;
      }
      cout << endl;

      for (auto t : edges) {
         cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
      }
   }
}
