#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int INF=987654321;
const int MAX=100;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int graph[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int x, int y, int cnt) // 각각의 섬에 대해 넘버링
{
    visited[x][y] = true;
    graph[x][y] = cnt;
    
    for(int dir=0; dir<4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(graph[nx][ny] && !visited[nx][ny]) dfs(nx,ny,cnt);
    }
}

int bfs(int cnt)
{
    queue<pair<int,int>> Q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(graph[i][j]==cnt)
            {
                visited[i][j]=true;
                Q.push({i,j});
            }

    int result=0;
    while(!Q.empty())
    {
        int curSize = Q.size();
        for(int i=0;i<curSize;i++)
        {
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(graph[nx][ny]!=0 && graph[nx][ny]!=cnt) return result;
                else if(graph[nx][ny]==0 && !visited[nx][ny])
                {
                    visited[nx][ny]=true;
                    Q.push({nx,ny});
                }
            }
        }
        result++;
    }
    return 9999;
}

int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    
    int cnt=1; // 섬의 수
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(graph[i][j] && !visited[i][j]) dfs(i,j,cnt++);
    
    int result = INF;
    for(int i=1;i<cnt;i++)
    {
        memset(visited,false,sizeof(visited));
        result = min(result, bfs(i));
    }
    
    cout<<result<<'\n';
    return 0;
}
