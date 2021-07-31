#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q; // bfs
int n, m;
int tomato[1000][1000], vis[1000][1000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n;
    fill(&vis[0][0], &vis[n-1][m], -1); // 2차원 배열 vis -1로 초기화
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> tomato[i][j]; // 토마토 값 입력 받음.
            if (tomato[i][j] == 1) { // 익은 토마토가 입력으로 들어오면 미리 큐에 삽입한다.
                Q.push({i, j});
                vis[i][j] = 0;
            }
        }
    
    while(!Q.empty()) // 각 익은 토마토로부터 bfs를 돌린다.
    {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] != -1 || tomato[nx][ny] != 0) continue;
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }
    
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (tomato[i][j] != -1 && vis[i][j] == -1){
                cout << -1 << '\n';
                return 0;
            }
            result = max(result, vis[i][j]);
        }
    }
    cout << result << '\n';
}
