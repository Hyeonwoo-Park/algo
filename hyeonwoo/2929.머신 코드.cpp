/*
	File: 2929.cpp
	Title: 머신 코드
	URL: https://www.acmicpc.net/problem/2929
	Input #1:
		EaEbFabG
	Output #1:
		5
	Created At: 2021-03-20 10:25:55.659559
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int lengths[27] = {0};
	string inp;
	int cnt = 0;
	cin >> inp;

	regex re("([A-Z])([a-z])*");

	regex_iterator<string::iterator> rit(inp.begin(), inp.end(), re);
	regex_iterator<string::iterator> rend;

	while (rit != rend)
	{
		string tmp = (rit++)->str();
		int cur_opcode = tmp[0] - 'A';

		lengths[cur_opcode] = max((int)tmp.length(), lengths[cur_opcode]);
	}

	rit = regex_iterator<string::iterator>(inp.begin(), inp.end(), re);

	while (rit != rend)
	{
		string tmp = (rit++)->str();
		int cur_opcode = tmp[0] - 'A';

		if (rit != rend)
		{
			cnt += (lengths[cur_opcode] - tmp.length());

			if (lengths[cur_opcode] % 4 != 0)
				cnt += 4 - lengths[cur_opcode] % 4;
		}
	}

	cout << cnt;
}