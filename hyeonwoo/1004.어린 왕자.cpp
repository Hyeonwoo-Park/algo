/*
	File: 1004.cpp
	Title: 어린 왕자
	URL: https://www.acmicpc.net/problem/1004
	Input #1:
		2
		-5 1 12 1
		7
		1 1 8
		-3 -1 1
		2 2 2
		5 5 1
		-4 5 1
		12 1 1
		12 1 2
		-5 1 5 1
		1
		0 0 2
	Output #1:
		3
		0
	Created At: 2021-02-01 13:27:31.451447
*/

#include <bits/stdc++.h>

using namespace std;

bool isIn(int p[], vector<int> circle)
{
	return sqrt(pow(abs(p[0] - circle[0]), 2) + pow(abs(p[1] - circle[1]), 2)) < circle[2];
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int sum = 0;

		int st[2], ed[2];
		cin >> st[0] >> st[1] >> ed[0] >> ed[1];

		int n;
		cin >> n;

		vector<vector<int>> planets(n, vector<int>(3));

		for (int i = 0; i < n; ++i)
		{
			cin >> planets[i][0] >> planets[i][1] >> planets[i][2];
		}

		for (vector<int> planet : planets)
		{
			bool a = isIn(st, planet);
			bool b = isIn(ed, planet);

			if (a != b)
				sum++;
		}

		cout << sum << endl;
	}
}