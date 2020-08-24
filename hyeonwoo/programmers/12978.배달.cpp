#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0, next = 0;
    vector< vector<int> > m(N, vector<int>(N,123456789));
    vector<bool> visit(N, false);
    
    
    for(int i = 0 ; i < road.size(); ++i){
        int st = road[i][0] - 1;
        int ed = road[i][1] - 1;
        int length = road[i][2];
        
        m[st][ed] = min(m[st][ed], length);
        m[ed][st] = min(m[ed][st], length);
    }
    
    m[0][0] = 0;
    next = 0;
    
    while(next != -1){
        int cur = next;
        next = -1;
        int minimum = 123456789;
        
        visit[cur] = true;
        
        for(int i = 0 ; i < N; ++i){
            if(visit[i]) continue;
            
            m[0][i] = min(m[0][i], m[0][cur] + m[cur][i]);
            
            if(minimum >= m[0][i]
                && !visit[i]){
                minimum = m[0][i];
                next = i;
            }
        }
    }
    
    for(int i = 0 ; i < N ; ++ i) if(m[0][i] <= K) answer++;
    
    return answer;
}