/*
	File: 2042.cpp
	Title: 구간 합 구하기
	URL: https://www.acmicpc.net/problem/2042
	Input #1:
		5 2 2
		1
		2
		3
		4
		5
		1 3 6
		2 2 5
		1 5 2
		2 3 5
	Output #1:
		17
		12
	Created At: 2020-08-25 21:53:38.847443
*/

#include <bits/stdc++.h>

using namespace std;

struct segtree{
	int st;
	int ed;
	long long value;
	segtree* leftnode ;
	segtree* rightnode;
};

segtree* treeInit(vector<long long>& roads, int st, int ed){
	segtree* newNode = new segtree();
	
	newNode->st = st;
	newNode->ed = ed;

	if(st == ed){
		newNode->value = roads[st];
	}else{
		newNode->leftnode  = treeInit(roads, st					, (st + ed) / 2	);
		newNode->rightnode = treeInit(roads, (st + ed) / 2 + 1	, ed			);

		newNode->value = newNode->leftnode->value + newNode->rightnode->value;
	}

	return newNode;
}

long long amend(segtree* curNode, int dest, long long value){
	if(curNode->st == dest && curNode->st == curNode->ed){
		long long diff = value - curNode->value;
		curNode->value = value;

		return diff;
	}

	long long diff;

	if(curNode->leftnode->st <= dest && curNode->leftnode->ed >= dest)
		diff = amend(curNode->leftnode, dest, value);
	else
		diff = amend(curNode->rightnode, dest, value);
	

	curNode->value += diff;

	return diff;
}

long long add(segtree* curNode, int st, int ed){
	if(curNode->st > ed || curNode->ed < st) return 0;

	if(curNode->st == st && curNode->ed == ed)
		return curNode->value;
	
	long long sum = 0;
	
	if(curNode->leftnode->ed >= ed){
		sum += add(curNode->leftnode, st, ed);
	} else if(curNode->leftnode->ed >= st){
		sum += add(curNode->leftnode, st, curNode->leftnode->ed);
		sum += add(curNode->rightnode, curNode->rightnode->st, ed);
	} else{
		sum += add(curNode->rightnode, st, ed);
	}

	return sum;
}

int main(){
	int N, M, K;
	cin>>N>>M>>K;
	vector<long long> num(N, 0);

	for(int i = 0; i < N; ++i)	cin>>num[i];

	segtree* Ntree = treeInit(num, 0, num.size() - 1);

	for(int i = 0; i < M + K; ++i){
		long long q1, q2, q3;
		cin>>q1>>q2>>q3;

		switch(q1){
			case 1:
				if(q2 <= 0 || q2 - 1 >= num.size()) continue;

				amend(Ntree, q2 - 1, q3);
				break;
			case 2:
				if(q2 > q3) swap(q2, q3);

				if(q2 - 1 < 0) q2 = 1;
				if(q3 - 1 >= num.size()) q3 = num.size();


				cout<<add(Ntree, q2 - 1, q3 -1)<<endl;
				break;
		}
	}

}