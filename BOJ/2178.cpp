#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
string arr[100];
int vis[100][100];

int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    fill(&vis[0][0], &vis[n-1][m], -1);
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vis[0][0] = 1;
    
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] != -1 || arr[nx][ny] == '0') continue;
            if(nx == n && ny == m)
            {
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                break;
            }
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }
    cout << vis[n-1][m-1] << '\n';
}
