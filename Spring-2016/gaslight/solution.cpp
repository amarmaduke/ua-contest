#include <bits/stdc++.h>

using namespace std;

// n = number of cities, m = miles to empty, k = number of connections
int n, m, k, t1, t2, distances[101], connections[101][101];

// going from city 1 to city n
int main() {
  cin >> n >> k >> m;

  for (int i = 0; i < k; ++i) {
    cin >> t1 >> t2;
    connections[t1 - 1][t2 - 1] = 1;
    connections[t2 - 1][t1 - 1] = 1;
  }

  fill(distances + 1, distances + n, -1);

  queue<int> nodes;
  nodes.push(0);

  while (!nodes.empty()) {
    int pos = nodes.front();
    nodes.pop();

    for (int i = 0; i < n; ++i) {
      if (connections[pos][i] && (distances[i] == -1)) {
        nodes.push(i);
        distances[i] = distances[pos] + 1;
      }
    }
  }

  cout << (distances[n - 1] == -1 || distances[n - 1] > m ? "No" : "Yes") << "\n";
}
