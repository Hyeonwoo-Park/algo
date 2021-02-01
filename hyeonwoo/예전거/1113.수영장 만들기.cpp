#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b)
{
	return a.size() < b.size();
}

vector<string> dfs(string str, int depth)
{
	vector<string> a;

	if (depth == 1)
	{
		for (auto const &aa : str)
		{
			a.push_back(string(1, aa));
		}

		return a;
	}

	for (int i = 0; i < str.size() - depth + 1; ++i)
	{
		vector<string> b = dfs(str.substr(i + 1), depth - 1);

		for (auto const &bb : b)
		{
			a.push_back(str[i] + bb);
		}
	}

	return a;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	sort(orders.begin(), orders.end(), compare);

	for (auto &order : orders)
		sort(order.begin(), order.end());

	for (auto const &c : course)
	{
		int ind = 0;

		cout << c << endl;
		while (ind < orders.size() && orders[ind].size() < c)
			ind++;

		map<string, int> fav;
		vector<vector<string>> orderCount(21);

		for (int i = ind; i < orders.size(); ++i)
		{
			vector<string> comb = dfs(orders[i], c);

			cout << orders[i] << endl;
			for (auto const &comb1 : comb)
			{
				cout << comb1 << ' ';
				if (fav.find(comb1) == fav.end())
				{
					fav[comb1] = 0;
				}
				fav[comb1]++;
			}
			cout << endl;
		}

		for (auto const &fav1 : fav)
		{
			orderCount[fav1.second].push_back(fav1.first);
		}

		for (int i = 20; i >= 0; --i)
		{
			if (orderCount[i].size() != 0)
			{
				cout << i << endl;
				for (auto const &o : orderCount[i])
				{
					cout << o << endl;
					answer.push_back(o);
				}
				break;
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	// vector<string> order = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
	vector<string> order = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
	vector<int> a = {2, 3, 5};
	solution(order, a);
}