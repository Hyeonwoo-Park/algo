
/*
    1012번 유기농 배추
    https://www.acmicpc.net/problem/1012


    입력 1:
    2
    10 8 17
    0 0
    1 0
    1 1
    4 2
    4 3
    4 5
    2 4
    3 4
    7 4
    8 4
    9 4
    7 5
    8 5
    9 5
    7 6
    8 6
    9 6
    10 10 1
    5 5

    출력 1:
    5
    1

    입력 2:
    1
    5 3 6
    0 2
    1 2
    2 2
    3 2
    4 2
    4 0
    출력 2:
    2
*/
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(vector<vector<int>> &cabbage, int x, int y)
{
    cabbage[x][y] = 0;

    for (int i = 0; i < 4; ++i)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (X < 0 || Y < 0 || X >= cabbage.size() || Y >= cabbage[0].size())
            continue;

        if (cabbage[X][Y] == 0)
            continue;

        dfs(cabbage, X, Y);
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int M, N, K, cnt = 0;
        cin >> M >> N >> K;
        vector<vector<int>> cabbage(M, vector<int>(N, 0));

        for (int i = 0; i < K; ++i)
        {
            int x, y;
            cin >> x >> y;
            cabbage[x][y] = 1;
        }

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (cabbage[i][j] == 1)
                {
                    cnt++;
                    dfs(cabbage, i, j);
                }
            }
        }

        cout << cnt << endl;
    }
}