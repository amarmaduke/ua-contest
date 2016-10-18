#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1 << 29;
int grid[401][401];
int ant_pos[11];
int larvae_pos[11];

void floyds(int n) {
   for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            if (grid[i][j] > grid[i][k] + grid[k][j]) {
               grid[i][j] = grid[i][k] + grid[k][j];
            }
         }
      }
   }
}

int solve(int a, int l, int e) {
   int result = 0;
   vector<int> larva;

   for (int i = 0; i < l; ++i)
      larva.push_back(larvae_pos[i]);

   while (larva.size() > 0) {
      int min_cost = MAX;
      int aid = -1;
      int lid = -1;
      for (int i = 0; i < a; ++i) {
         for (int j = 0; j < larva.size(); ++j) {
            if (grid[ant_pos[i]][larva[j]] < min_cost) {
               aid = i;
               lid = j;
               min_cost = grid[ant_pos[i]][larva[j]];
            }
         }
      }

      result += min_cost;
      ant_pos[aid] = larva[lid];
      larva.erase(larva.begin() + lid);
   }

   for (int i = 0; i < a; ++i) {
      result += grid[ant_pos[i]][e];
   }

   return result;
}

int main() {
   while (true) {
      int n, m;
      cin >> n >> m;
      if (n == 0 && m == 0) break;

      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            if (i == j) {
               grid[i][j] = 0;
            } else {
               grid[i][j] = MAX;
            }
         }
      }

      int ants, larvae, e;
      cin >> ants >> larvae >> e;

      for (int i = 0; i < ants; ++i) {
         int id;
         cin >> id;
         ant_pos[i] = id;
      }

      for (int i = 0; i < larvae; ++i) {
         int id;
         cin >> id;
         larvae_pos[i] = id;
      }

      for (int i = 0; i < m; ++i) {
         int u, v, c;
         cin >> u >> v >> c;
         grid[u][v] = c;
         grid[v][u] = c;
      }

      floyds(n);
      cout << solve(ants, larvae, e) << endl;
   }
}
