#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	long long answer = 40000000001;
	vector<vector<long long>> graph(n, vector<long long>(n, 40000000001));
	s--;
	a--;
	b--;

	for (int i = 0; i < n; ++i)
	{
		graph[i][i] = 0;
	}

	for (auto const &fare : fares)
	{
		int st = fare[0] - 1;
		int ed = fare[1] - 1;
		int cost = fare[2];

		graph[st][ed] = cost;
		graph[ed][st] = cost;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				graph[j][i] = graph[i][j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		answer = min(graph[s][i] + graph[a][i] + graph[b][i], answer);
	}

	return answer;
}

int main()
{
	int n = 7, s = 3, a = 4, b = 1;
	vector<vector<int>> fare = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};

	solution(n, s, a, b, fare);
}