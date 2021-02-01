/*
	File: 2261.cpp
	Title: 가장 가까운 두 점
	URL: https://www.acmicpc.net/problem/2261
	Input #1:
		4
		0 0
		10 10
		0 10
		10 0
	Output #1:
		100
	Created At: 2020-09-20 19:21:23.161887
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> point;

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		point.emplace_back(x, y);
	}
}