#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
   int id;
   vector<Node*> arcs;
   vector<int> costs;
};

const int NODE_COUNT = 101;
const int INF = 1000000;
int dist[NODE_COUNT];
int parent[NODE_COUNT];
bool visited[NODE_COUNT];

struct cmp {
   bool operator() (const int left, const int right)
   {
      return dist[left] < dist[right];
   }
};

vector<pair<int, int> > get_edges(int source, int target)
{
   vector<pair<int, int> > edges;

   int current = target;
   while (current != source and parent[current] != 0)
   {
      pair<int, int> p = make_pair(parent[current], current);
      edges.push_back(p);
      current = parent[current];
   }
   return edges;
}

void dijkstra(int source, vector<Node*>& graph, pair<int, int> ignore)
{
   fill(dist, dist + NODE_COUNT, INF);
   fill(parent, parent + NODE_COUNT, 0);
   fill(visited, visited + NODE_COUNT, false);

   dist[source] = 0;
   visited[source] = true;
   priority_queue<int, vector<int>, cmp> pq;

   pq.push(source);

   while (not pq.empty())
   {
      int current = pq.top();
      pq.pop();

      vector<Node*>& arcs = graph[current - 1]->arcs;
      vector<int>& costs = graph[current - 1]->costs;
      for (int i = 0; i < arcs.size(); ++i)
      {
         int other = arcs[i]->id;
         if (not visited[other])
            pq.push(other);
         if (current == ignore.first and other == ignore.second)
            continue;
         int update = dist[current] + costs[i];
         if (update < dist[other])
         {
            dist[other] = update;
            parent[other] = current;
         }
      }
   }
}

int main()
{
   int v, e, target;

   do {
      cin >> v >> e;
      if (v == 0 and e == 0) break;

      cin >> target;

      vector<Node*> nodes;

      for (int i = 0; i < v; ++i)
      {
         Node* n = new Node();
         n->id = i + 1;
         nodes.push_back(n);
      }

      for (int i = 0; i < e; ++i)
      {
         int x, y, c;
         cin >> x >> y >> c;
         nodes[x - 1]->arcs.push_back(nodes[y - 1]);
         nodes[x - 1]->costs.push_back(c);
      }

      int shortest = INF, shortest2 = INF;

      dijkstra(1, nodes, make_pair(0, 0));
      vector<pair<int, int> > ignore = get_edges(1, target);

      shortest = dist[target];

      for (int i = 0; i < ignore.size(); ++i)
      {
         dijkstra(1, nodes, ignore[i]);
         shortest2 = min(shortest2, dist[target]);
      }

      if (shortest2 == INF)
         cout << "Impossible!" << endl;
      else
         cout << shortest2 << endl;

   } while(v != 0 or e != 0);
}
