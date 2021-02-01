/*
	File: 2188.cpp
	Title: 축사 배정
	URL: https://www.acmicpc.net/problem/2188
	Input #1:
		5 5
		2 2 5
		3 2 3 4
		2 1 5
		3 1 2 5
		1 2
	Output #1:
		4
	Created At: 2020-09-09 13:02:32
*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> & vertex, vector<int> &R, vector<bool> &visit, int st){

	for(auto const & ed : vertex[st]){
		if(R[ed] == -1){
			R[ed] = st;

			return true;
		}

		if(visit[ed]) continue;

		visit[ed] = true;

		if(dfs(vertex, R, visit, R[ed])){
			R[ed] = st;

			return true;
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, cnt = 0;

	cin>>N>>M;

	vector<int> R(M, -1);
	vector<vector<int>> vertex(N, vector<int>());

	for(int i = 0 ; i < N ; ++i){
		int len;
		cin>>len;
		while(len--){
			int inp;
			cin>>inp;

			vertex[i].push_back(inp - 1);
		}
	}	

	for(int i = 0 ; i < N; ++i){
		vector<bool> visit(M, false);

		dfs(vertex, R, visit, i);
	}

	for(auto const & r : R){
		if(r != -1) cnt++;
	}

	cout<<cnt;
}