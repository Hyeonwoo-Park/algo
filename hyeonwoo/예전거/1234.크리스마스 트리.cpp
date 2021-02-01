#include <bits/stdc++.h>

using namespace std;

int sum = 0;
vector<vector<pair<int, int>>> positions;

int dist(vector<vector<int>> board, pair<int, int> st, pair<int, int> ed)
{
	bool exist = false;
	queue<pair<int, int>> Q;
	int len = -1;
	int qs = 0;

	Q.push(st);

	while (!Q.empty())
	{
		int curX = Q.front().first;
		int curY = Q.front().second;

		if (qs == 0)
		{
			len++;
			qs = Q.size();
		}

		Q.pop();

		int dx = 0, dy = 0;

		if (curX < ed.first)
		{
			dx = 1;
		}
		else if (curX > ed.first)
		{
			dx = -1;
		}

		if (curY < ed.second)
		{
			dy = 1;
		}
		else if (curY > ed.second)
		{
			dy = -1;
		}

		if (dx)
		{
			int tmpX = curX + dx;

			if (!board[tmpX][curY])
			{
				Q.push(make_pair(tmpX, curY));
			}

			for (; board[tmpX][curY] && tmpX != ed.first; tmpX += dx)
				;
			Q.push(make_pair(tmpX, curY));
		}

		if (dy)
		{
			int tmpY = curY + dy;

			if (!board[curX][tmpY])
			{
				Q.push(make_pair(curX, tmpY));
			}

			for (; board[curX][tmpY] && tmpY != ed.second; tmpY += dy)
				;
			Q.push(make_pair(curX, tmpY));
		}
		qs--;
	}

	return len;
}

int dfs(vector<vector<int>> &board, vector<bool> &visit, int r, int c, int cost, int suc)
{
	if (suc == 0)
		return cost;

	int minimum = 1234567890;

	for (int i = 1; i <= 6; ++i)
	{
		if (visit[i])
			continue;
		if (positions[i].size() == 0)
			continue;

		visit[i] = true;
		board[positions[i][0].first][positions[i][0].second] = 0;
		board[positions[i][1].first][positions[i][1].second] = 0;

		int x = positions[i][0].first;
		int y = positions[i][0].second;
		int length = dist(board, make_pair(r, c), positions[i][1]) + dist(board, positions[i][1], positions[i][0]);

		minimum = min(dfs(board, visit, x, y, length, suc - 1), minimum);

		x = positions[i][1].first;
		y = positions[i][1].second;
		length = dist(board, make_pair(r, c), positions[i][0]) + dist(board, positions[i][0], positions[i][1]);

		minimum = min(dfs(board, visit, x, y, length, suc - 1), minimum);

		board[positions[i][0].first][positions[i][0].second] = i;
		board[positions[i][1].first][positions[i][1].second] = i;
		visit[i] = false;
	}

	return minimum;
}

int solution(vector<vector<int>> board, int r, int c)
{
	int answer = 0;

	int total = 0;

	vector<bool> visit(7, false);
	positions.assign(7, vector<pair<int, int>>());

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j])
			{
				positions[board[i][j]].push_back(make_pair(i, j));
				total++;
			}
		}
	}

	total /= 2;

	return dfs(board, visit, r, c, 0, total);
}

int main()
{
	vector<vector<int>> board = {{1, 0, 0, 3},
								 {2, 0, 0, 0},
								 {0, 0, 0, 2},
								 {3, 0, 1, 0}};
	int r = 1, c = 0;
	cout << solution(board, r, c);
}