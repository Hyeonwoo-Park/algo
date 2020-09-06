/*
	File: 8972.cpp
	Title: 미친 아두이노
	URL: https://www.acmicpc.net/problem/8972
	Input #1:
		9 10
		..........
		.........R
		..........
		R.........
		R...I.....
		R.........
		..........
		.........R
		....R.....
		5558888
	Output #1:
		....I.....
		....R.....
		..........
		..........
		..........
		..........
		..........
		..........
		..........
	Created At: 2020-08-30 20:16:56.205426
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

pair<int, int> operator+(pair<int, int> l, pair<int, int> r)
{
	return make_pair(l.first + r.first, l.second + r.second);
}

void printField(int R, int C, pair<int, int> js, list<pair<int, int>> madRobots)
{
	vector<vector<char>> game(R, vector<char>(C, '.'));

	game[js.first][js.second] = 'I';

	for (auto const &madRobot : madRobots)
	{
		game[madRobot.first][madRobot.second] = 'R';
	}

	for (auto const &g1 : game)
	{
		for (auto const &g2 : g1)
		{
			cout << g2;
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	string moves;
	pair<int, int> js;
	list<pair<int, int>> madRobots;
	bool endFlag = false;
	int m = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char inp;
			cin >> inp;

			if (inp == 'I')
			{
				js.first = i;
				js.second = j;
			}
			else if (inp == 'R')
			{
				madRobots.emplace_back(i, j);
			}
		}
	}

	cin >> moves;

	for (auto const &move : moves)
	{
		m++;
		js.first += dx[move - '0'];
		js.second += dy[move - '0'];

		for (auto &madRobot : madRobots)
		{
			pair<int, int> closest = madRobot + make_pair(dx[1], dy[1]);

			for (int i = 2; i <= 9; ++i)
			{
				pair<int, int> tmpPair = madRobot + make_pair(dx[i], dy[i]);

				if (dist(js, closest) > dist(js, tmpPair))
					closest = tmpPair;
			}

			madRobot = closest;
		}

		madRobots.sort();

		bool bombFlag = false;

		for (auto it = madRobots.begin(); it != madRobots.end(); it++)
		{
			if (*it == js)
			{
				endFlag = true;
				break;
			}

			auto it2 = it;
			it2++;

			if (it2 != madRobots.end() && *it == *it2)
			{
				it = madRobots.erase(it);
				it--;

				bombFlag = true;
			}
			else if (bombFlag)
			{
				it = madRobots.erase(it);
				it--;

				bombFlag = false;
			}
		}

		if (endFlag)
			break;
	}

	if (endFlag)
		cout << "kraj " << m;
	else
	{
		printField(N, M, js, madRobots);
	}
}