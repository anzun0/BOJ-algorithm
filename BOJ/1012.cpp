#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t;
int board[51][51], vis[51][51];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        fill(&board[0][0], &board[50][51], 0);
        fill(&vis[0][0], &vis[50][51], 0);
        
        queue<pair<int, int>> Q; // BFS queue
        int m, n, k; // m: 가로, n: 세로, k: 배추 수
        int ans = 0; // 출력 결과
        cin >> m >> n >> k;
        
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1; // 배추 좌표
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1 && vis[i][j] == 0) {
                    Q.push({i, j});
                    vis[i][j] = 1;
                    ans++;
                }
                
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
