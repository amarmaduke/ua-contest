#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lights[101];
bool roads[101][101];
bool done [101];

struct node 
{
	int d;
	int i;
	
	node(int dis, int idx) 
	{
			d = dis;
			i = idx;
	}
	
	bool operator < (const node& other)  const
	{
		return d < other.d;
	}
};

int main()
{
	while (true)
	{
		int n;
		int r;
		cin >> n >> r;
		
		if (n == 0 && r == 0) 
		{
			break;
		}
		
		for (int i = 0; i < n; ++i) 
		{
			int num;
			char color;
			cin >> num;
			cin >> color;
			lights[num] = color == 'G';
		}
		
		for (int i = 0; i < 101; ++i)
		{
			for (int j = 0; j < 101; ++j) 
			{
				roads[i][j] = false;
			}
		}
		
		for (int i = 0; i < r; ++i) 
		{
			int a;
			int b;
			cin >> a >> b;
			
			roads[a][b] = true;
			roads[b][a] = true;
		}
		
		int start;
		int end;
		cin >> start >> end;
		
		vector<node> queue;
		if (lights[start])
		{
			queue.push_back(node(0, start));
		}
		else
		{
			queue.push_back(node(1, start));
		}
		
		for (int i = 0; i < 101; ++i) 
		{
			done[i] = false;
		}
		
		int best = 1000000;
		
		while (queue.size() > 0)
		{
			node cur = queue[0];
			queue.erase(queue.begin());
			done[cur.i] = true;
			
			for (int i = 0; i <= n; ++i) 
			{
				if (!done[i] && roads[cur.i][i])
				{
					int wait = 0;
					if ((cur.d % 2 == 1 && lights[cur.i]) || (cur.d % 2 == 0 && !lights[cur.i]))
					{
						wait = 1;
					}
					
					if (i != end)
					{
						queue.push_back(node(cur.d + 1 + wait, i));
					}
					
					if (i == end && cur.d + 1 < best)
					{
						best = cur.d + 1;
					}
				}
			}
			
			sort(queue.begin(), queue.end());
		}
		
		cout << best << endl;
	}
	
	return 0;
}