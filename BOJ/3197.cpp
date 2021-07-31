#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int R, C, result, sx, sy;
bool meet, vis[1500][1500];
char lake[1500][1500];
queue<pair<int, int>> SQ, SQ_temp, WQ, WQ_temp;

void move()
{
    while (!SQ.empty())
    {
        auto cur = SQ.front(); SQ.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || vis[nx][ny]) continue;
            if (lake[nx][ny] == '.') SQ.push({ nx,ny });
            else if (lake[nx][ny] == 'X') SQ_temp.push({ nx,ny });
            else if (lake[nx][ny] == 'L')
            {
                meet = true;
                return;
            }
            vis[nx][ny] = true;
        }
    }
}

void melt()
{
    while (!WQ.empty())
    {
        auto cur = WQ.front(); WQ.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (lake[nx][ny] == 'X')
            {
                WQ_temp.push({ nx,ny });
                lake[nx][ny] = '.';
            }
        }
    }
}

void ClearQueue(queue<pair<int, int>>& someQueue)
{
    queue<pair<int, int>> empty;
    swap(someQueue, empty);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> lake[i][j];
            if (lake[i][j] == '.' || lake[i][j] == 'L') WQ.push({ i,j });
            if (lake[i][j] == 'L')
            {
                sx = i; sy = j;
            }
        }
    SQ.push({ sx,sy });
    vis[sx][sy] = true;

    while (!meet)
    {
        move();
        if (meet) break;
        melt();
        SQ = SQ_temp; WQ = WQ_temp;
        ClearQueue(SQ_temp); ClearQueue(WQ_temp);
        result++;
    }
    cout << result;
    return 0;
}

