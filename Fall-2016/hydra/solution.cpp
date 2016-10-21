#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
   int depth;
   vector<int> children;
   int parent;
};

vector<Node> nodes;
set<int> leafs;

void debug() {
   for (int i = 1; i < nodes.size(); ++i) {
      if (nodes[i].depth > -1) {
         cout << i << " (p:" << nodes[i].parent << ")(d:" << nodes[i].depth << ")(c:";


         for (int j = 0; j < nodes[i].children.size(); ++j) {
            cout << nodes[i].children[j];
            if (j + 1 != nodes[i].children.size())
               cout << " ";
         }
         cout << ") ";
      }
   }
   cout << endl;

   for (auto x : leafs) {
      cout << x << " ";
   }
   cout << endl << endl;
}

void zdepth(int depth, int pos) {
   nodes[pos].depth = depth;
   for (int i = 0; i < nodes[pos].children.size(); ++i) {
      zdepth(depth+1, nodes[pos].children[i]);
   }
}

int zfind() {
   int siblings = 0;
   int pick = 0;
   int depth = 0;
   for (auto&& i : leafs) {
      int parent = nodes[i].parent;
      if (nodes[i].depth > depth) {
         siblings = nodes[parent].children.size();
         pick = i;
         depth = nodes[i].depth;
      } else if (nodes[i].depth == depth) {
         if (nodes[parent].children.size() > siblings) {
            siblings = nodes[parent].children.size();
            pick = i;
            depth = nodes[i].depth;
         }
      }
   }
   return pick;
}

int zcopy(int node) {
   Node x;
   x.depth = nodes[node].depth;
   x.parent = nodes[node].parent;
   int result = nodes.size();
   nodes.push_back(x);

   for (int i = 0; i < nodes[node].children.size(); ++i) {
      int t = zcopy(nodes[node].children[i]);
      nodes[result].children.push_back(t);
      nodes[t].parent = result;
   }

   return result;
}

void set_leafs(int node) {
   if (nodes[node].children.size() == 0 && node != 1) {
      leafs.insert(node);
   }

   for (int i = 0; i < nodes[node].children.size(); ++i) {
      set_leafs(nodes[node].children[i]);
   }
}

void zcut(int head) {
   nodes[nodes[head].parent].children
      .erase(
         find(nodes[nodes[head].parent].children.begin(),
            nodes[nodes[head].parent].children.end(),
            head));
   leafs.erase(leafs.find(head));

   int parent = nodes[head].parent;
   int grandparent = nodes[parent].parent;

   if (grandparent > 0) {
      int c = zcopy(parent);
      nodes[grandparent].children.push_back(c);
      zdepth(nodes[grandparent].depth + 1, c);
      set_leafs(c);
   }
   set_leafs(parent);

   nodes[head].parent = -1;
   nodes[head].depth = -1;
}

int solve() {
   int result = 0;
   zdepth(0, 1);
   set_leafs(1);
   while (leafs.size() > 0) {
      int to_cut = zfind();
      zcut(to_cut);
      ++result;
   }
   return result;
}

int main() {
   while (true) {
      int n;
      cin >> n;
      if (n == 0) break;

      int m = n - 1;

      nodes.clear();

      for (int i = 0; i <= n; ++i) {
         Node x;
         nodes.push_back(x);
      }

      for (int i = 0; i < m; ++i) {
         int from, to;
         cin >> from >> to;
         nodes[from].children.push_back(to);
         nodes[to].parent = from;
      }

      cout << solve() << endl;
   }
}
