#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
#ifndef SINGLE_FILE
	int count;
	cin >> count;

	for (int countIndex = 0; countIndex < count; ++countIndex)
	{
#endif

		int n;
		cin >> n;

		vector<vector<int>> memo = vector<vector<int>>(max(n, 2), vector<int>(3, 0));

		memo[0][0] = 0;
		memo[1][0] = 1;

		memo[0][1] = 1;
		memo[1][1] = 1;

		memo[0][2] = 1;
		memo[1][2] = 2;

		for (int i = 2; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				memo[i][j] = memo[i-1][(j+1)%3] + memo[i-2][(j+2)%3]; 
			}
		}

		cout << memo[n-1][0] << ' ' << memo[n-1][1] << ' ' << memo[n-1][2] << endl;

#ifndef SINGLE_FILE
	}
#endif
}