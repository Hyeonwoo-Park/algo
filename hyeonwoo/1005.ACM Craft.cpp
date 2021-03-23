/*
	File: 1005.cpp
	Title: ACM Craft
	URL: https://www.acmicpc.net/problem/1005
	Input #1:
		2
		4 4
		10 1 100 10
		1 2
		1 3
		2 4
		3 4
		4
		8 8
		10 20 1 5 8 7 1 43
		1 2
		1 3
		2 4
		2 5
		3 6
		5 7
		6 7
		7 8
		7
	Output #1:
		120
		39
	Input #2:
		5
		3 2
		1 2 3
		3 2
		2 1
		1
		4 3
		5 5 5 5
		1 2
		1 3
		2 3
		4
		5 10
		100000 99999 99997 99994 99990
		4 5
		3 5
		3 4
		2 5
		2 4
		2 3
		1 5
		1 4
		1 3
		1 2
		4
		4 3
		1 1 1 1
		1 2
		3 2
		1 4
		4
		7 8
		0 0 0 0 0 0 0
		1 2
		1 3
		2 4
		3 4
		4 5
		4 6
		5 7
		6 7
		7
	Output #2:
		6
		5
		399990
		2
		0
	Created At: 2021-02-03 10:32:33.388396
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> seqs;
vector<int> ds, dp;

void dfs(int cur)
{
	int maximum = 0;

	for (auto ed : seqs[cur])
	{
		if (dp[ed] == -1)
			dfs(ed);

		maximum = max(dp[ed], maximum);
	}

	dp[cur] = maximum + ds[cur];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int N, K, W;
		cin >> N >> K;

		ds.assign(N, 0);
		dp.assign(N, -1);
		seqs.assign(N, vector<int>());

		for (int i = 0; i < N; ++i)
			cin >> ds[i];

		for (int i = 0; i < K; ++i)
		{
			int st, ed;
			cin >> st >> ed;

			seqs[ed - 1].push_back(st - 1);
		}

		cin >> W;

		dfs(W - 1);

		cout << dp[W - 1] << endl;
	}
}