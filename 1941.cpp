#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans;
string maps[5];
bool select_girl[25];

bool MoreThanFour() // 이다솜파가 4명 이상 포함되었는지를 확인
{
    int cnt=0;
    for(int i=0;i<25;i++)
    {
        if(select_girl[i])
        {
            int x = i / 5;
            int y = i % 5;
            if(maps[x][y]=='S') cnt++;
        }
    }
    if(cnt>=4) return true;
    return false;
}

bool Adjancency() // 선택한 원소들이 모두 인접한 지를 확인
{
    queue<pair<int,int>> Q;
    bool check_select[5][5]; // 선택된 원소들만 따로 표시
    bool queue_select[5][5]; // bfs를 위한 visited배열
    bool check_answer=false;
    
    memset(check_select, false, sizeof(check_select));
    memset(queue_select, false, sizeof(queue_select));
    
    int tmp=0;
    for(int i=0;i<25;i++)
        if(select_girl[i]) // i번째 원소가 선택된 경우
        {
            int x = i / 5;
            int y = i % 5;
            check_select[x][y]=true;
            
            if(tmp==0) // 시작점 설정
            {
                Q.push({x,y});
                queue_select[x][y]=true;
                tmp++;
            }
        }
    
    int cnt=1;
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        if(cnt==7)
        {
            check_answer=true;
            break;
        }
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(check_select[nx][ny] && !queue_select[nx][ny]) // 선택된 원소(아직 방문하지 않은 경우)
            {
                queue_select[nx][ny]=true;
                Q.push({nx,ny});
                cnt++;
            }
        }
    }
    if(check_answer) return true;
    return false;
}

void dfs(int idx, int k)
{
    if(k==7)
    {
        if(MoreThanFour())
            if(Adjancency())
                ans++;
        return;
    }
    for(int i=idx; i<25; i++) // 0~24까지의 조합을 구함
    {
        if(select_girl[i]) continue;
        select_girl[i]=true;
        dfs(i, k+1);
        select_girl[i]=false;
    }
}

int main(void)
{
    for(int i=0;i<5;i++)
        cin>>maps[i];
    dfs(0, 0);
    cout<<ans<<'\n';
    return 0;
}
