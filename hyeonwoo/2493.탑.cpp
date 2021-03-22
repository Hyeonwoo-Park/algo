/*
	File: 2493.cpp
	Title: 탑
	URL: https://www.acmicpc.net/problem/2493
	Input #1:
		5
		6 9 5 7 4
	Output #1:
		0 0 2 2 4
	Created At: 2021-02-04 16:55:55.645924
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> answers(N, 0);
	vector<int> towers(N);
	stack<pair<int, int>> s;

	for (int i = 0; i < N; ++i)
	{
		cin >> towers[i];
	}

	s.push(make_pair(100000001, 0));

	for (int i = 0; i < N; ++i)
	{
		int tower = towers[i];

		while (s.top().first < tower)
		{
			s.pop();
		}

		answers[i] = s.top().second;

		s.push(make_pair(tower, i + 1));
	}

	for (auto answer : answers)
		cout << answer << ' ';
}