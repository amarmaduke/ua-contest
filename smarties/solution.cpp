#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long dp[101][101][101][5];

long long solve(vector<int>& in, int left, int right, int run, int prev, int steps)
{
	if (dp[left][right][run][prev] != -1)
	{
		return dp[left][right][run][prev];
	}
	
	if (left == right)
	{
		return in[left] * steps * (in[left] == prev ? run + 1 : 1);
	}
	
	long long leftScore = in[left] * steps * (in[left] == prev ? run + 1 : 1);
	long long leftBest = solve(in, left + 1, right, prev == in[left] ? run + 1 : 1, in[left], steps + 1);
	long long rightScore = in[right] * steps * (in[right] == prev ? run + 1 : 1);
	long long rightBest = 0;//solve(in, left, right - 1, prev == in[right] ? run + 1 : 1, in[right], steps + 1);
	
	long long best = max(leftScore + leftBest, rightScore + rightBest);
	
	dp[left][right][run][prev] = best;
	
	return best;
}

int main()
{
	while (true)
	{
		int n;
		string s;
		cin >> n;
		cin >> s;
		
		if (n == 0)
		{
			break;
		}
		
		vector<int> in;
		
		for (int i = 0; i < n; ++i) 
		{
			if (s[i] == 'R')
			{
				in.push_back(4);
			}
			else if (s[i] == 'B')
			{
				in.push_back(3);
			}
			else if (s[i] == 'G')
			{
				in.push_back(2);
			}
			else
			{
				in.push_back(1);
			}
		}
		
		for (int i = 0; i < 101; ++i)
		{
			for (int j = 0; j < 101; ++j)
			{
				for (int k = 0; k < 101; ++k)
				{
					for (int l = 0; l < 5; ++l)
					{
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
		
		cout << solve(in, 0, n - 1, 1, 0, 1) << endl;
	}
	
	return 0;
}