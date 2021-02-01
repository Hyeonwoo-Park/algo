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
	Created At: 2020-09-01 03:27:11.476546
*/

#include <bits/stdc++.h>

using namespace std;

void find(vector<vector<int>> &down, int num, int depthCount, vector<vector<int>> &depth, queue<int> &Q)
{
	cout << depthCount << endl;
	while (depth.size() <= depthCount)
	{
		depth.push_back(vector<int>());
	}

	depth[depthCount].push_back(num);

	for (auto const &d : down[num])
	{
		find(down, d, depthCount + 1, depth, Q);
	}
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int N, K, W;

		cin >> N >> K;

		queue<int> Q;
		vector<vector<int>> depth;
		vector<vector<int>> down(N);
		vector<int> times(N);
		vector<bool> visit(N, false);

		for (int i = 0; i < N; ++i)
		{
			cin >> times[i];
		}

		for (int i = 0; i < K; ++i)
		{
			int X, Y, Z;
			cin >> X >> Y;

			down[Y - 1].push_back(X - 1);
		}

		cin >> W;

		find(down, W - 1, 0, depth, Q);

		for (int i = depth.size() - 1; i >= 0; --i)
		{
			for (auto const &d1 : depth[i])
			{
				if (visit[d1])
					continue;
				visit[d1] = true;

				Q.push(d1);
			}
		}

		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();

			int max_d = 0;
			for (const auto &d : down[cur])
			{
				if (times[d] >= max_d)
					max_d = times[d];
			}

			times[cur] += max_d;
		}

		cout << times[W - 1] << '\n';
	}
}