/*
	File: 16686.cpp
	Title: 실시간 내비게이션
	URL: https://www.acmicpc.net/problem/16686
	Input #1:
		7
		1 2 1 1 1 2
		1 1 1 3 3 1
		10 9 7 12 11 8 10
		6
		1 N2 S4
		4 6 2
		1 N3 S5
		3 3 8
		2 4 2
		1 N2 S4
	Output #1:
		10
		8
		14
	Input #2:
		4
		1 1000000000 1
		1000000000 1 1000000000
		1000000000 1 1 1000000000
		1
		1 N1 N4
	Output #2:
		5
	Created At: 2020-08-25 09:40:13.568361
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct segtree{
	int value;
	segtree* leftnode = null;
	segtree* rightnode= null;
};

segtree* treeInit(vector<int>& roads, int st, int ed){
	segtree* newNode = new segtree();

	if(st == ed){
		newNode->value = roads[st];
	}else{
		newNode->leftnode  = treeInit(roads, st					, (st + ed) / 2	);
		newNode->rightnode = treeInit(roads, (st + ed) / 2 + 1	, ed			);

		newNode->value = newNode->leftnode->value + newNode->rightnode->value;
	}

	return newNode;
}

int main(){
	int n,Q;
	cin>>n;
	vector<int> N(n, 0);
	vector<int> S(n, 0);
	vector<int> B(n, 0);

	for(int i = 0; i < n - 1; ++i)	cin>>N[i];
	for(int i = 0; i < n - 1; ++i)	cin>>S[i];
	for(int i = 0; i < n    ; ++i)	cin>>B[i];

	segtree* Ntree = treeInit(N, 0, N.size() - 1);
	segtree* Ntree = treeInit(S, 0, S.size() - 1);

	cin>>Q;

	for(int i = 0; i < Q; ++i){
		int q1, q2, q3;
		cin>>q1>>q2>>q3;

		switch(q1){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				break;
		}
	}

}