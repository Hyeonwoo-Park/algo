#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

bool flag = false;

int dfs(vector<int> const & money, int ind){
    if(ind == money.size() - 1){
        if(flag)
            return money[ind];
        else
            return 0;
    }else if(ind == money.size()) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    dp[ind] = max(money[ind] + dfs(money, ind + 2), dfs(money, ind + 1));
    
    return dp[ind];
}

int solution(vector<int> money) {
    int answer = 0;
    
    dp.assign(money.size(), -1);
    answer = dfs(money, 0);
    
    flag = true;
    dp.assign(money.size(), -1);
    answer = max(answer, dfs(money, 1));
    
    return answer;
}