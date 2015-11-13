#include <iostream>
#include <map>
#include <set>

typedef std::map<int, std::map<int, int> > grid;

void print_states(grid& g1, int s)
{
	using namespace std;
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			cout << g1[i][j];
			if (j + 1 != s)
				cout << " ";
		}
		cout << endl;
	}
}

grid rand_state(int s)
{
	grid out;
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			int x = rand() % 2;
			out[i][j] = x;
		}
	}
	return out;
}

grid get_state(grid& g, std::set<int>& survival, std::set<int>& birth, int s)
{
	grid out;
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			int count = 0;
			for (int di = -1; di <= 1; ++di)
			{
				for (int dj = -1; dj <= 1; ++dj)
				{
					count += g[i + di][j + dj]; 
				}
			}
			count -= g[i][j];

			if (g[i][j] == 0) // Birth?
			{
				if (birth.count(count) == 1)
					out[i][j] = 1;
			} else if (g[i][j] == 1) // Survival?
			{
				if (survival.count(count) == 1)
					out[i][j] = 1;
			}
		}
	}
	return out;
}

int main()
{
	using namespace std;
	cout << "83" << endl;
	cout << "5" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << "0 0 1 1 0" << endl;
	cout << "0 0 1 0 1" << endl;
	cout << "0 0 1 0 0" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << endl;
	cout << "0 0 0 0 0" << endl;
	cout << "0 0 1 1 0" << endl;
	cout << "0 1 1 0 0" << endl;
	cout << "0 0 0 1 0" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << "5" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << "0 1 1 1 0" << endl;
	cout << "0 1 0 1 0" << endl;
	cout << "0 1 1 1 0" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << endl;
	cout << "0 1 0 1 0" << endl;
	cout << "1 0 0 0 1" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << "1 0 0 0 1" << endl;
	cout << "0 1 0 1 0" << endl;
	cout << "5" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << "0 0 1 1 0" << endl;
	cout << "0 0 1 0 1" << endl;
	cout << "0 0 1 0 0" << endl;
	cout << "0 0 0 0 0" << endl;
	cout << endl;
	cout << "1 0 0 0 0" << endl;
	cout << "0 0 1 1 0" << endl;
	cout << "0 0 1 0 0" << endl;
	cout << "0 0 0 1 0" << endl;
	cout << "0 1 0 0 0" << endl;

	for (int i = 0; i < 70; ++i)
	{
		int s = rand() % 100;
		set<int> survival;
		set<int> birth;
 		for (int i = 0; i < 5; ++i)
		{
			int a = rand() % 8;
			int b = rand() % 8;
			survival.insert(a);
			birth.insert(b);
		}
		grid g1 = rand_state(s);
		grid g2 = get_state(g1, survival, birth, s);
		cout << s << endl;
		print_states(g1, s);
		cout << endl;
		print_states(g2, s);
	}

	for (int i = 0; i < 10; ++i)
	{
		int s = rand() % 100;
		grid g1 = rand_state(s);
		grid g2 = rand_state(s);
		cout << s << endl;
		print_states(g1, s);
		cout << endl;
		print_states(g2, s);
	}
}
