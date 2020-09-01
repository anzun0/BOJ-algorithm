#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0}; // 0: 북, 1: 동, 2: 남, 3: 서
int dy[4] = {0, 1, 0, -1};

int result;
int n, m, x, y, dir;
int MAP[50][50];
queue<pair<pair<int,int>, int>> Q;

int main(void)
{
    cin >> n >> m >> x >> y >> dir;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>MAP[i][j];
    Q.push({ {x,y}, dir });
    
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        if(MAP[cur.X.X][cur.X.Y]==0)
        {
            MAP[cur.X.X][cur.X.Y] = 2; // 로봇 청소기가 청소한 공간을 따로 표시
            result++;
        }
        
        bool flag = false;
        for(int k = 0; k < 4; k++)
        {
            int ndir = (cur.Y + (3 - k)) % 4; // 왼쪽으로 계속 회전
            int nx = cur.X.X + dx[ndir];
            int ny = cur.X.Y + dy[ndir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(!MAP[nx][ny]) // 청소할 공간이 있다면 전진
            {
                Q.push({ {nx, ny}, ndir });
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            int beforeX = cur.X.X - dx[cur.Y];
            int beforeY = cur.X.Y - dy[cur.Y];
            // 이미 청소된 칸도 다시 되돌아 갈 수 있다! (따라서 MAP 값이 0, 2일떄 가능)
            if(beforeX<0 || beforeX >=n || beforeY<0 || beforeY>=m || MAP[beforeX][beforeY] == 1) break;
            else
                Q.push({ {beforeX, beforeY}, cur.Y });
        }
    }
    cout<<result<<'\n';
    return 0;
}
