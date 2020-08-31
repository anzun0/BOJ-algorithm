#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string puyo[12];

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.Y == b.Y)
        return a.X < b.X;
    return a.Y < b.Y;
}

int bfs()
{
    queue<pair<int,int>> Q;
    int cnt = 0;
    
    while(true)
    {
        vector<pair<int,int>> v; // 한꺼번에 터트릴 뿌요 담아두기
        bool visited[12][6] = {false, };
        
        for(int x = 11; x >= 0; x--)
        {
            for(int y = 0; y < 6; y++)
            {
                if(puyo[x][y]=='.') continue;
                
                queue<pair<int,int>> group;
                char color = puyo[x][y];;
                Q.push({x,y}); visited[x][y] = true;
                
                while(!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    
                    group.push({cur.X, cur.Y});
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || nx>=12 || ny<0 || ny>=6 || visited[nx][ny]) continue;
                        if(color == puyo[nx][ny])
                        {
                            Q.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
                if(group.size()>=4)
                {
                    while(!group.empty())
                    {
                        v.push_back({group.front().X, group.front().Y});
                        group.pop();
                    }
                }
            }
        }

        if(v.size() != 0)
        {
            sort(v.begin(), v.end(), cmp);
            for(int i = 0; i < v.size(); i++)
            {
                for(int j = v[i].X; j > 0; j--)
                    puyo[j][v[i].Y] = puyo[j-1][v[i].Y]; // 한 칸씩 아래로 떨어트림
                puyo[0][v[i].Y] = '.'; // 꽉 차있는 경우를 대비
            }
            cnt++;
        }
        else break; // 한바퀴를 돌았는데도 연쇄가 일어날 수 있는 뿌요가 없는 경우
    }
    return cnt;
}

int main(void)
{
    for(int i=0;i<12;i++)
        cin >> puyo[i];
    cout<<bfs()<<'\n';
    return 0;
}
