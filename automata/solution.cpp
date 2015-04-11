#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

typedef std::map< int, std::map<int, int> > grid;

int adj_count(grid& g, int x, int y)
{
	int out = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			out += g[x + i][y + j];
		}
	}
	out -= g[x][y];
	return out;
}

int main()
{
	using namespace std;
	int kases;
	cin >> kases;
	for (int k = 0; k < kases; ++k)
	{
		grid state1;
		grid state2;
		int s;
		cin >> s;
	
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s; ++j)
			{
				int x;
				cin >> x;
				state1[i][j] = x;
			}
		}

		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s; ++j)
			{
				int x;
				cin >> x;
				state2[i][j] = x;
			}
		}

		set<int> birth_rules;
		set<int> survival_rules;
		set<int> death_rules;
		set<int> vacuum_rules;

		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s; ++j)
			{
				int count = adj_count(state1, i, j);
				int f = state1[i][j];
				int s = state2[i][j];

				if (f == 1 and s == 1)
				{ // Alive -> Alive. Survival
					survival_rules.insert(count);
				} else if (f == 1 and s == 0)
				{ // Alive -> Dead. Death
					death_rules.insert(count);
				} else if (f == 0 and s == 1)
				{ // Dead -> Alive. Birth
					birth_rules.insert(count);
				} else if (f == 0 and s == 0)
				{ // Dead -> Dead. Vacuum
					vacuum_rules.insert(count);
				}
			}
		}

		set<int> check_survival;
		set<int> check_birth;

		set_intersection(survival_rules.begin(), survival_rules.end(),
				 death_rules.begin(), death_rules.end(),
				 std::inserter(check_survival, check_survival.begin()));
		set_intersection(birth_rules.begin(), birth_rules.end(),
				 vacuum_rules.begin(), vacuum_rules.end(),
				 std::inserter(check_birth, check_birth.begin()));

		if (check_survival.empty() and check_birth.empty())
		{
			typedef set<int>::iterator iter_t;
			cout << "S";
			for (iter_t it = survival_rules.begin(); it != survival_rules.end(); ++it)
			{
				cout << *it;
			}
			cout << "/B";
			for (iter_t it = birth_rules.begin(); it != birth_rules.end(); ++it)
			{
				cout << *it;
			}
			cout << endl;
		} else
		{
			cout << "Not Possible." << endl;
		}
	}
	return 0;
}
