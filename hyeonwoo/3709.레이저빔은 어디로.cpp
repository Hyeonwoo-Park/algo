/*
	File: 3709.cpp
	Title: 레이저빔은 어디로
	URL: https://www.acmicpc.net/problem/3709
	Input #1:
		2
		2 3
		1 1
		1 2
		2 2
		3 1
		3 6
		1 1
		1 3
		2 2
		2 3
		3 1
		3 2
		2 0
	Output #1:
		2 0
		0 2
	Created At: 2020-08-23 00:50:19.506949
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

pair<int, int> f(vector< vector<int> > & board, int x, int y, int dir, vector< vector< vector< int> > > &visit){
	int X = x + dx[dir];
	int Y = y + dy[dir];

	if( X == 0 || Y == 0 || X == board.size() || Y == board.size()){
		return make_pair(X,Y);
	} 

	if(board[X][Y] == 1){
		dir = (dir + 1) % 4;
	}

	if(visit[X][Y][dir] == 1) return make_pair(0, 0);

	visit[X][Y][dir] = 1;

	return f(board, X, Y, dir, visit);
}

int main() {
	int TC;
	cin>>TC;

	while(TC--){
		int N,r,x,y;
		pair<int, int> result; 

		cin>>N>>r;

		vector< vector<int> > board(N + 1, vector<int> (N + 1, 0));
		vector< vector< vector<int> > > visit(N + 1, vector< vector< int> > (N + 1, vector<int>(4, 0)));

		for(int i = 0; i < r; ++i){
			cin>>x>>y;
			board[x][y] = 1;
		}

		cin>>x>>y;

		if( x == 0){
			result = f(board, x, y, 3, visit);
		}else if( x == N + 1){
			result = f(board, x, y, 1, visit);
		}else if( y == 0){
			result = f(board, x, y, 2, visit);
		}else{
			result = f(board, x, y, 0, visit);
		}

		cout<<result.first<<' '<<result.second<<'\n';
	}
}