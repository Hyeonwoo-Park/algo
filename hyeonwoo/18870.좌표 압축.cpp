/*
	File: 18870.cpp
	Title: 좌표 압축
	URL: https://www.acmicpc.net/problem/18870
	Input #1:
		5
		2 4 -10 4 -9
	Output #1:
		2 3 0 3 1
	Input #2:
		6
		1000 999 1000 999 1000 999
	Output #2:
		1 0 1 0 1 0
	Created At: 2021-03-20 12:38:11.583369
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> numbers(N);
	vector<int> zipped;
	set<int> s;

	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
		s.insert(numbers[i]);
	}

	for (auto number : s)
	{
		zipped.push_back(number);
	}

	for (int i = 0; i < N; ++i)
	{
		auto it = lower_bound(zipped.begin(), zipped.end(), numbers[i]);

		cout << (it - zipped.begin()) << ' ';
	}
}