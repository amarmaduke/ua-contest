#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// cat <<< "n m" | ./gen >> input

vector<int> is_connected(vector<pair<int, int> > &edges, int n)
{
   vector<bool> visited(n);
   vector<int> lonely_nodes;
   fill(visited.begin(), visited.end(), false);
   queue<int> searchq;
   searchq.push(0);
   while (not searchq.empty())
   {
      int current = searchq.front();
      searchq.pop();
      for (int i = 0; i < edges.size(); ++i)
      {
         pair<int, int> val = edges[i];
         if (val.first == current and not visited[val.second])
         {
            searchq.push(val.second);
         } else if (val.second == current and not visited[val.first])
         {
            searchq.push(val.first);
         }
         visited[current] = true;
      }
   }
   for (int i = 0; i < visited.size(); ++i)
   {
      if (not visited[i])
      {
         lonely_nodes.push_back(i);
      }
   }
   return lonely_nodes;
}

int main()
{
   int n, m;
   cin >> n >> m;
   srand(time(0));

   vector<pair<int, int> > edges;
   map<int, map<int, bool> > exists;
   vector<int> processing = is_connected(edges, n);

   while (not processing.empty())
   {
      for (int i = 0; i < processing.size(); ++i)
      {
         for (int k = 0; k < 1000; ++k)
         {
            int current = processing[i];
            int target = rand() % n;
            if (not exists[current][target] and not exists[target][current] and current != target)
            {
               exists[current][target] = true;
               exists[target][current] = true;
               edges.push_back(make_pair(current, target));
               break;
            }
         }
      }
      processing = is_connected(edges, n);
   }

   cout << n << " " << edges.size() << " " << m << endl;
   for(int i = 0; i < edges.size(); ++i)
   {
      pair<int, int> val;
      val = edges[i];
      cout << (val.first + 1) << " " << (val.second + 1) << endl;
   }
}
