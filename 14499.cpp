#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0}; // 1:동, 2:서, 3:북, 4:남

int n, m, x, y, k;
int MAP[20][20], dice[7];

void move(int dir, int nx, int ny)
{
    int ndice[7]; // dir 방향으로 구른 이후의 주사위
    switch(dir){
        case 0: // 동쪽으로 굴리는 경우
            ndice[1] = dice[4];
            ndice[2] = dice[2];
            ndice[3] = dice[1];
            ndice[4] = dice[6];
            ndice[5] = dice[5];
            ndice[6] = dice[3];
            break;
        case 1: // 서쪽으로 굴리는 경우
            ndice[1] = dice[3];
            ndice[2] = dice[2];
            ndice[3] = dice[6];
            ndice[4] = dice[1];
            ndice[5] = dice[5];
            ndice[6] = dice[4];
            break;
        case 2: // 북쪽으로 굴리는 경우
            ndice[1] = dice[5];
            ndice[2] = dice[1];
            ndice[3] = dice[3];
            ndice[4] = dice[4];
            ndice[5] = dice[6];
            ndice[6] = dice[2];
            break;
        case 3: // 남쪽으로 굴리는 경우
            ndice[1] = dice[2];
            ndice[2] = dice[6];
            ndice[3] = dice[3];
            ndice[4] = dice[4];
            ndice[5] = dice[1];
            ndice[6] = dice[5];
            break;
    }
    
    if(MAP[nx][ny] == 0)
        MAP[nx][ny] = ndice[6];
    else{
        ndice[6] = MAP[nx][ny];
        MAP[nx][ny] = 0;
    }
    
    cout<<ndice[1]<<'\n'; // 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력!
    for(int i = 1; i < 7; i++) dice[i] = ndice[i];
    return;
}

int main(void)
{
    cin>>n>>m>>x>>y>>k; //(x,y)는 주사위의 시작 위치이자, 나중에는 현재 위치로 사용됨
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>MAP[i][j]; // 지도 입력
    
    for(int i=0;i<k;i++) // k번의 이동
    {
        int dir;
        cin>>dir;
        dir--;
        
        // 지도 상에서 이동
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0 || nx >=n || ny<0 || ny>=m) continue;
        else{
            move(dir, nx, ny);
            x = nx; y = ny;
        }
    }
    return 0;
}
