/*
	File: 9935.cpp
	Title: 문자열 폭발
	URL: https://www.acmicpc.net/problem/9935
	Input #1:
		mirkovC4nizCC44
		C4
	Output #1:
		mirkovniz
	Input #2:
		12ab112ab2ab
		12ab
	Output #2:
		FRULA
	Created At: 2020-09-01 01:58:35.900154
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string tmp, bomb;
	list<char> origin;
	cin >> tmp;
	cin >> bomb;

	origin.assign(tmp.begin(), tmp.end());

	for (auto o = origin.begin(); o != origin.end(); o++)
	{
		int b = 0;
		auto p = o;

		for (; p != origin.end() && b < bomb.size(); ++b, ++p)
		{
			if (*p != bomb[b])
				break;
		}

		if (b == bomb.size())
		{
			o = origin.erase(o, p);

			while (b-- && o != origin.begin())
			{
				o--;
			}

			if (o == origin.begin())
				o--;
		}
	}

	if (origin.empty())
		cout << "FRULA";
	else
	{
		while (!origin.empty())
		{
			cout << origin.front();
			origin.pop_front();
		}
	}
}