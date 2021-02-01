/*
	File: 6198.cpp
	Title: 옥상 정원 꾸미기
	URL: https://www.acmicpc.net/problem/6198
	Input #1:
		6
		10
		3
		7
		4
		12
		2
	Output #1:
		5
	Created At: 2020-08-23 01:24:10.073677
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	long long sum = 0;

	cin>>N;

	stack<int> stk;
	vector<int> height(N);
	
	for(int i = 0 ; i < N; ++i){
		cin>> height[i];
	}

	for(int i = N - 1; i >= 0; --i){
		while( !stk.empty() && ( height[stk.top()] < height[i] ) ){
			stk.pop();
		}

		if(stk.empty()) sum += N - 1 - i;
		else			sum += stk.top() - i - 1;

		stk.push(i);
	}

	cout<<sum<<endl;
}