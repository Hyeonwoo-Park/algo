#include<vector>
#include<queue>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int qSize = 0;
    
    bool success = false;
    queue<pair<int, int>> Q;
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), 0));
    Q.emplace(0,0);
    
    while(!Q.empty()){
        if(!qSize){
            qSize = Q.size();
            answer++;
        }
        
        int x = Q.front().first;
        int y = Q.front().second;
        
        Q.pop();
        qSize--; 
        
        if(x == maps.size() - 1 && y == maps[0].size() - 1)
            return answer;
        
        
        for(int i = 0 ; i < 4 ; ++i){
            int X = x + dx[i];
            int Y = y + dy[i];
            
            if(X < 0 || Y < 0 || X >= maps.size() || Y >= maps[0].size()) continue;
            if(maps[X][Y] == 0) continue;
            if(visit[X][Y]) continue;
            
            visit[X][Y] = true;
            
            Q.emplace(X, Y);
        }
        
          
    }
    
    return -1;
}