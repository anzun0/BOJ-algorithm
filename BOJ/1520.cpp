#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, ans;
int board[500][500], vis[500][500], d[500][500]; // DP memoization

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (vis[x][y]) return d[x][y];
    
    vis[x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (board[nx][ny] >= board[x][y]) continue;
        d[x][y]+= dfs(nx, ny);
    }
    return d[x][y];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    cout << dfs(0, 0) <<'\n';
}
