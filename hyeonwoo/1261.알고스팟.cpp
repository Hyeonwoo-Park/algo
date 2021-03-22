/*
	File: 1261.cpp
	Title: 알고스팟
	URL: https://www.acmicpc.net/problem/1261
	Input #1:
		3 3
		011
		111
		110
	Output #1:
		3
	Input #2:
		4 2
		0001
		1000
	Output #2:
		0
	Input #3:
		6 6
		001111
		010000
		001111
		110001
		011010
		100010
	Output #3:
		2
	Created At: 2021-03-22 12:56:26.128653
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(vector<vector<int>> &room, vector<vector<int>> &dp, int x, int y, int depth)
{
	dp[x][y] = depth;

	if (x == room.size() && y == room[0].size())
		return;

	for (int i = 0; i < 4; ++i)
	{
		int X = x + dx[i];
		int Y = y + dy[i];

		if (X < 0 || Y < 0 || X >= room.size() || Y >= room[0].size())
			continue;

		if (dp[X][Y] <= depth + room[X][Y])
			continue;

		dfs(room, dp, X, Y, depth + room[X][Y]);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> room(M, vector<int>(N));
	vector<vector<int>> dp(M, vector<int>(N, 10001));

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char tmp;
			cin >> tmp;
			room[i][j] = tmp - '0';
		}
	}

	dfs(room, dp, 0, 0, 0);

	cout << dp[M - 1][N - 1];
}