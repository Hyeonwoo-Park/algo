/*
	File: 6118.cpp
	Title: 숨바꼭질
	URL: https://www.acmicpc.net/problem/6118
	Input #1:
		6 7
		3 6
		4 3
		3 2
		1 3
		1 2
		2 4
		5 2
	Output #1:
		4 2 3
	Created At: 2020-08-02 18:00:47.892575
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector< vector<int>> route(N + 1);
    vector<int> visit(N + 1 ,0);
    vector<int> same;
    queue<int> Q1;
    queue<int> Q2;
    int dist = 0;

    for(int i = 0; i < M; ++i){
        int a, b;
        cin>>a>>b;

        route[a].push_back(b);
        route[b].push_back(a);
    }
    visit[1] = 1;
    Q1.push(1);

    while(!Q1.empty() || !Q2.empty()){
        if(Q1.empty()){
            same.clear();
            while(!Q2.empty()){
                Q1.push(Q2.front());
                same.push_back(Q2.front());
                Q2.pop();
            }

            dist++;
        }

        int a = Q1.front();
        Q1.pop();

        for(int i = 0 ; i < route[a].size(); ++i){
            int b = route[a][i];

            if(visit[b] == 0){
                Q2.push(b);
                visit[b] = 1;
            }
        }
    }

    sort(same.begin(), same.end());

    cout<<same[0]<<' '<<dist<<' '<<same.size();
}
