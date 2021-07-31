#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int W, H, vis[100][100]; // W*H 지도
char map[100][100]; // 방문 여부와 해당 점까지의 거울 개수의 최소를 나타냄
vector<pair<int, int>> V;

int bfs(int x1, int y1)
{
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    for (int dir = 0; dir < 4; dir++)
        Q.push(MP(MP(x1, y1), MP(dir, 0))); // 시작점에 대한 방향

    while (!Q.empty())
    {
        int x = (Q.front().X).X;
        int y = (Q.front().X).Y;
        int dir = (Q.front().Y).X;
        int count = (Q.front().Y).Y;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next_count = count;

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (map[nx][ny] == '*') continue;
            if (dir != i) next_count = count + 1;
            if (vis[nx][ny] == -1 || vis[nx][ny] >= next_count)
            {
                vis[nx][ny] = next_count;
                Q.push(MP(MP(nx, ny), MP(i, next_count)));
            }
        }
    }
    return vis[V[1].X][V[1].Y];
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'C')
                V.push_back({ i,j });
        }
    memset(vis, -1, sizeof(vis));
    cout << bfs(V[0].X, V[0].Y);

    return 0;
}
