#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> match = {
	{"cpp", "java", "python"},
	{"backend", "frontend"},
	{"junior", "senior"},
	{"chicken", "pizza"}};

vector<vector<vector<vector<vector<int>>>>> srch(4,
												 vector<vector<vector<vector<int>>>>(3,
																					 vector<vector<vector<int>>>(3,
																												 vector<vector<int>>(3))));

vector<string> sliceBySep(string query, string const &sep, bool const &q)
{
	vector<string> result;
	size_t ind = query.find(sep);

	while (ind != -1)
	{
		result.push_back(query.substr(0, ind));

		query = query.substr(ind + sep.size());

		ind = query.find(sep);
	}

	if (q)
	{
		ind = query.find(" ");
		result.push_back(query.substr(0, ind));

		query = query.substr(ind + 1);
	}

	result.push_back(query);

	return result;
}

vector<int> translate(vector<string> const &vec)
{
	vector<int> result;

	result.push_back(stoi(vec[4]));

	for (int i = 0; i < 4; ++i)
	{
		if (vec[i] == "-")
		{
			if (i == 0)
				result.push_back(3);
			else
				result.push_back(2);
			continue;
		}

		for (int j = 0; j < match[i].size(); ++j)
		{
			if (vec[i] == match[i][j])
			{
				result.push_back(j);
				break;
			}
		}
	}

	return result;
}

void append(vector<int> const &v)
{

	srch[v[1]][v[2]][v[3]][v[4]].push_back(v[0]);
	srch[v[1]][v[2]][v[3]][2].push_back(v[0]);
	srch[v[1]][v[2]][2][v[4]].push_back(v[0]);
	srch[v[1]][v[2]][2][2].push_back(v[0]);
	srch[v[1]][2][v[3]][v[4]].push_back(v[0]);
	srch[v[1]][2][v[3]][2].push_back(v[0]);
	srch[v[1]][2][2][v[4]].push_back(v[0]);
	srch[v[1]][2][2][2].push_back(v[0]);

	srch[3][v[2]][v[3]][v[4]].push_back(v[0]);
	srch[3][v[2]][v[3]][2].push_back(v[0]);
	srch[3][v[2]][2][v[4]].push_back(v[0]);
	srch[3][v[2]][2][2].push_back(v[0]);
	srch[3][2][v[3]][v[4]].push_back(v[0]);
	srch[3][2][v[3]][2].push_back(v[0]);
	srch[3][2][2][v[4]].push_back(v[0]);
	srch[3][2][2][2].push_back(v[0]);
}

void sorting()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				for (int l = 0; l < 3; ++l)
				{
					sort(srch[i][j][k][l].begin(), srch[i][j][k][l].end(), greater<int>());
				}
			}
		}
	}
}

vector<int> solution(vector<string> const &info, vector<string> const &query)
{
	vector<vector<int>> vv;
	vector<int> answer;

	for (auto const &info1 : info)
	{
		vv.push_back(translate(sliceBySep(info1, " ", false)));
	}

	sort(vv.begin(), vv.end(), greater<vector<int>>());

	for (auto const &vvv : vv)
	{
		append(vvv);
	}

	for (auto const &q : query)
	{
		vector<int> sq = translate(sliceBySep(q, " and ", true));
		int sum = 0;

		for (auto const &score : srch[sq[1]][sq[2]][sq[3]][sq[4]])
		{
			if (score < sq[0])
				break;

			sum++;
		}

		answer.push_back(sum);
	}

	return answer;
}

int main()
{
	vector<string> info = {"java backend junior pizza 150",
						   "python frontend senior chicken 210",
						   "python frontend senior chicken 150",
						   "cpp backend senior pizza 260",
						   "java backend junior chicken 80",
						   "python backend senior chicken 50"};
	vector<string> query = {"java and backend and junior and pizza 100",
							"python and frontend and senior and chicken 200",
							"cpp and - and senior and pizza 250",
							"- and backend and senior and - 150",
							"- and - and - and chicken 100",
							"- and - and - and - 150"};

	solution(info, query);
}