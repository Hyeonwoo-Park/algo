/*
	File: 2473.cpp
	Title: 세 용액
	URL: https://www.acmicpc.net/problem/2473
	Input #1:
		5
		-2 6 -97 -6 98
	Output #1:
		-97 -2 98
	Created At: 2020-09-09 20:06:06.726043
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	vector<int> A;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	int result = 0;
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				if (A[i] < A[j] && A[i] > A[k])
					result++;
			}
		}
	}

	cout << result;
}