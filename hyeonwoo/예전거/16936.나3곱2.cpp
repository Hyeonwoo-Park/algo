/*
	File: 16936.cpp
	Title: 나3곱2
	URL: https://www.acmicpc.net/problem/16936
	Input #1:
		6
		4 8 6 3 12 9
	Output #1:
		9 3 6 12 4 8
	Input #2:
		4
		42 28 84 126
	Output #2:
		126 42 84 28
	Created At: 2020-09-30 18:56:00.559975
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> dfs(vector<int> &B, map<int, int> &m, int x, int ind)
{
	if (ind == 0)
	{
		vector<int> result;
		result.push_back(x);

		return result;
	}

	if (x % 3 == 0 && m.find(x / 3) != m.end())
	{
		int tmp = B[x / 3];
		B[x / 3] = -1;
		vector<int> result = dfs(B, m, x / 3, ind - 1);

		if (result.size() == ind)
			return result;

		B[x / 3] = tmp;
	}
}

int main()
{

	int N;
	cin >> N;

	map<int, int> m;
	vector<int> B(N);
	vector<int> A(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
		m.emplace(B[i], i);
	}

	for (int i = 0; i < N; ++i)
	{
	}
}