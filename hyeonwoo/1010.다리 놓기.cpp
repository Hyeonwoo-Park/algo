/*
	File: 1010.cpp
	Title: 다리 놓기
	URL: https://www.acmicpc.net/problem/1010
	Input #1:
		3
		2 2
		1 5
		13 29
	Output #1:
		1
		5
		67863915
	Created At: 2020-08-28 08:33:33.822300
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<vector<int>> dp(30, vector<int>(30, 1));

	for (int i = 1; i < 30; ++i)
	{
		for (int j = i + 1; j < 30; ++j)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;

		cout << dp[N][M] << endl;
	}
}