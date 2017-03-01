#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int id;
    int dist;
    bool done;
    string label;
    vector<int> edges;
};

struct Order
{
    bool operator() (const Node *lhs, const Node *rhs)
    {
        return lhs->dist > rhs->dist;
    }
};

int dist(string a, string b)
{
    int result = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        result += !(a[i] == b[i]);
    }
    return result;
}

vector<Node> nodes;
int INF = 1 << 30;

void dijkstra(int source)
{
    priority_queue<Node*, vector<Node*>, Order> queue;
    for (int i = 0; i < nodes.size(); ++i)
    {
        nodes[i].dist = INF;
        nodes[i].done = false;
    }
    nodes[source].dist = 0;
    queue.push(&nodes[source]);

    while (!queue.empty())
    {
        Node* current = queue.top(); queue.pop();
        current->done = true;

        for (int i = 0; i < current->edges.size(); ++i)
        {
            int u = current->edges[i];
            if (nodes[u].done) continue;
            queue.push(&nodes[u]);
            int alt = current->dist + dist(current->label, nodes[u].label);
            if (alt < nodes[u].dist)
            {
                nodes[u].dist = alt;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        string label;
        cin >> label;
        Node n;
        n.label = label;
        n.id = i;
        nodes.push_back(n);
    }

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        nodes[l].edges.push_back(r);
        nodes[r].edges.push_back(l);
    }

    int s;
    cin >> s;
    dijkstra(s);

    for (int i = 0; i < nodes.size(); ++i)
    {
        int d = nodes[i].dist == INF ? -1 : nodes[i].dist;
        cout << nodes[i].label << " " << d << endl;
    }
}