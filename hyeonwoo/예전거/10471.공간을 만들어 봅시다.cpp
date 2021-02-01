/*
	File: 10471.cpp
	Title: 공간을 만들어 봅시다
	URL: https://www.acmicpc.net/problem/10471
	Input #1:
		10 3
		1 4 8
	Output #1:
		1 2 3 4 6 7 8 9 10
	Input #2:
		6 2
		2 5
	Output #2:
		1 2 3 4 5 6
	Created At: 2020-09-11 11:49:36
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int W, P;
	cin>>W>>P;
	vector<int> partitions;
	partitions.push_back(0);
	for(int i = 0 ; i < P; ++i){
		int tmp;
		cin>>tmp;
		partitions.push_back(tmp);
	}
	partitions.push_back(W);
	
	set<int> space;

	for(int i = 0 ; i < partitions.size() - 1; ++i){
		for(int j = i + 1; j < partitions.size(); ++j){
			space.insert(partitions[j] - partitions[i]);
		}
	}

	for(auto const & s : space)
		cout<<s<<' ';
}