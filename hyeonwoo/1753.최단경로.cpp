/*
	File: 1753.cpp
	Title: 최단경로
	URL: https://www.acmicpc.net/problem/1753
	Input #1:
		5 6
		1
		5 1 1
		1 2 2
		1 3 3
		2 3 4
		2 4 5
		3 4 6
	Output #1:
		0
		2
		3
		7
		INF
	Created At: 2020-08-25 22:11:10.694497
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int V, E, next, start;
	cin >> V >> E;
	cin >> start;

	vector<map<int, int>> graph(V);
	vector<bool> visit(V, false);
	vector<int> shortestPath(V, 1234567890);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int prev = graph[a - 1][b - 1];

		if (prev)
		{
			graph[a - 1][b - 1] = min(prev, c);
		}
		else
		{
			graph[a - 1][b - 1] = c;
		}
	}

	shortestPath[start - 1] = 0;
	pq.push(make_pair(0, start - 1));

	while (!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();
		if (visit[cur])
			continue;

		int minimum = 1234567890;
		visit[cur] = true;

		for (const auto &kv : graph[cur])
		{
			int dest = kv.first;
			int length = kv.second;

			shortestPath[dest] = min(shortestPath[dest], shortestPath[cur] + length);

			pq.push(make_pair(shortestPath[dest], dest));
		}
	}

	for (int i = 0; i < V; ++i)
	{
		if (shortestPath[i] == 1234567890)
			cout << "INF" << '\n';
		else
			cout << shortestPath[i] << '\n';
	}
}