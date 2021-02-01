#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int lx[] = {0, -1, 0, 1};
int ly[] = {1, 0, -1, 0};

bool existLeft(vector<vector<int>> &maze, int x, int y, int dir)
{
	int X = x + lx[dir];
	int Y = y + ly[dir];

	if (X == -1 || Y == -1 || X == maze.size() || Y == maze.size() || maze[X][Y] == 1)
		return true;
	return false;
}

bool blocked(vector<vector<int>> &maze, int x, int y, int dir)
{
	int X = x + dx[dir];
	int Y = y + dy[dir];

	if (X < 0 || Y < 0 || X >= maze.size() || Y >= maze.size() || maze[X][Y] == 1)
		return true;
	return false;
}

int srch(vector<vector<int>> &maze, int x, int y, int dir)
{
	cout << x << ' ' << y << ' ' << dir << endl;
	if (x == maze.size() - 1 && y == maze.size() - 1)
	{
		return 0;
	}

	if (!existLeft(maze, x, y, dir))
	{
		dir = (dir + 1) % 4;
		int X = x + dx[dir];
		int Y = y + dy[dir];
		return srch(maze, X, Y, dir) + 1;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (!blocked(maze, x, y, dir))
			break;
		dir = dir - 1 < 0 ? 3 : dir - 1;
	}

	int X = x + dx[dir];
	int Y = y + dy[dir];

	return srch(maze, X, Y, dir) + 1;
}

int solution(vector<vector<int>> maze)
{
	int answer = 0;
	return srch(maze, 0, 0, 0);
}

int main()
{
	// vector<vector<int>> maze = {{0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}, {1, 0, 1, 0}};
	vector<vector<int>> maze =
		{{0, 1, 0, 0, 0, 0},
		 {0, 1, 0, 1, 1, 0},
		 {0, 1, 0, 0, 1, 0},
		 {0, 1, 1, 1, 1, 0},
		 {0, 1, 0, 0, 0, 0},
		 {0, 0, 0, 1, 1, 0}};

	cout << solution(maze);
}