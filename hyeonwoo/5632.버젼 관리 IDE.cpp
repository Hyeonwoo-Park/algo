/*
	File: 5632.cpp
	Title: 버젼 관리 IDE
	URL: https://www.acmicpc.net/problem/5632
	Input #1:
		6
		1 0 abcdefgh
		2 4 3
		3 1 2 5
		3 3 3 4
		1 4 xy
		3 5 4 6
	Output #1:
		bcdef
		bcg
		bxyc
	Created At: 2021-03-20 10:17:25.695897
*/

#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

vector<crope> ropes;
int d = 0;

void op1()
{
	crope new_rope = ropes.back();
	int p;
	string s;
	cin >> p >> s;

	new_rope.insert(p - d, s.c_str());
	ropes.push_back(new_rope);
}

void op2()
{
	crope new_rope = ropes.back();
	int p, c;
	cin >> p >> c;

	new_rope.erase(p - d - 1, c - d);
	ropes.push_back(new_rope);
}

void op3()
{
	int v, p, c;
	cin >> v >> p >> c;

	string str = ropes[v - d].substr(p - d - 1, c - d).c_str();

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == 'c')
			d++;
	}

	cout << str << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ropes.push_back(crope());
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int opcode;
		cin >> opcode;

		switch (opcode)
		{
		case 1:
			op1();
			break;
		case 2:
			op2();
			break;
		case 3:
			op3();
			break;
		default:
			break;
		}
	}
}