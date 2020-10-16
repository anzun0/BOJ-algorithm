#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, vis[100][100];
string grid[100];

void colorblind()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 'G') grid[i][j] = 'R';
    return;
}

int bfs(int x, int y)
{
    int cnt = 0;
    memset(vis, -1, sizeof(vis));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] != -1) continue;
            cnt++;

            queue<pair<int, int>> Q;
            Q.push({ i,j }); vis[i][j] = 1;

            while (!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny] != -1 || grid[nx][ny] != grid[cur.X][cur.Y]) continue;
                    Q.push({ nx,ny });
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> grid[i];
    cout << bfs(0, 0) << ' ';
    colorblind();
    cout << bfs(0, 0);
    
    return 0;
}
