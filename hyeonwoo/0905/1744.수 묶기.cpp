/*
	File: 1744.cpp
	Title: 수 묶기
	URL: 	
	Input #1:
		4
		-1
		2
		1
		3
	Output #1:
		6
	Created At: 2020-09-01 03:30:33.108687
*/

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> num;
vector<int> dp;

int f(int ind)
{
	if (dp[ind] != 1234567890)
		return dp[ind];

	dp[ind] = max(num[ind] * num[ind + 1] + f(ind + 2), num[ind] + f(ind + 1));

	return dp[ind];
}

int main()
{
	int N;
	cin >> N;

	num.assign(N, 0);
	dp.assign(N, 1234567890);

	for (int i = 0; i < N; ++i)
	{
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	dp[N - 1] = num[N - 1];

	if (N > 1)
		dp[N - 2] = max(num[N - 1] + num[N - 2], num[N - 1] * num[N - 2]);

	f(0);

	cout << dp[0];
}