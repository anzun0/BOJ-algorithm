#include <bits/stdc++.h>
using namespace std;

struct state {
    int eff;
    char ele;
    
    state() { }
    state(int _eff,char _ele) : eff(_eff),ele(_ele) { }
};

int n,result=INT_MIN;
int efficacy[10][4][4][4]; // 10은 재료번호, 4는 회전 방향, 4는 x좌표, 4는 y좌표
char element[10][4][4][4]; // 10은 재료번호, 4는 회전 방향, 4는 x좌표, 4는 y좌표
bool visited[10];

vector<vector<state>> bomb(5,vector<state>(5));

// 입력 배열을 90도로 3번 회전하여 각각을 저장하는 함수
void rotateArr(int type,int dir){
    // 90 도 회전
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){ //
            efficacy[type][dir][i][j] = efficacy[type][dir-1][3-j][i];
            element[type][dir][i][j] = element[type][dir-1][3-j][i];
        }
    }
}

// 폭탄의 최대 품질을 구하는 함수
int getQuality(vector<vector<state>> v){
    int r = 0;
    int b = 0;
    int g = 0;
    int y = 0;
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            switch (v[i][j].ele) {
                case 'R':
                    r += v[i][j].eff;
                    break;
                case 'B':
                    b += v[i][j].eff;
                    break;
                case 'G':
                    g += v[i][j].eff;
                    break;
                case 'Y':
                    y += v[i][j].eff;
                    break;
                default:
                    break;
            }
        }
    }
    
    return 7*r + 5*b + 3*g + 2*y;
}

// 가마에 재료의 종류, 방향에 따라 재료를 놓는 함수
vector<vector<state>> putMaterial(vector<vector<state>> v,int row,int col,int type,int dir){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            // 효능
            v[row+i][col+j].eff += efficacy[type][dir][i][j];
            
            if(v[row+i][col+j].eff < 0)
                v[row+i][col+j].eff = 0;
            else if(v[row+i][col+j].eff > 9)
                v[row+i][col+j].eff = 9;
            
            // 원소
            if(element[type][dir][i][j] != 'W'){
                v[row+i][col+j].ele = element[type][dir][i][j];
            }
        }
    }
    
    return v;
}

void dfs(vector<vector<state>> v,int cnt){
    // 재료 3개를 모두 선택한 경우
    if(cnt == 3){
        result = max(result,getQuality(v));
        return;
    }
    
    // dfs
    for(int t=0; t<n; t++){
        if(!visited[t]){
            visited[t] = true;
            
            for(int i=0; i<=1; i++)
                for(int j=0; j<=1; j++) // (0,0), (0,1), (1,0), (1,1)
                    for(int d=0; d<4; d++){ // 4가지 회전 방향에 대해서 체크
                        vector<vector<state>> tmp = putMaterial(v,i,j,t,d);
                        dfs(tmp,cnt+1);
                    }
            visited[t] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int t=0; t<n; t++)
    {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                cin >> efficacy[t][0][i][j]; // 효능 입력
        
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                cin >> element[t][0][i][j]; // 원소 입력
        
        for(int d=1; d<=3; d++)
            rotateArr(t,d); // 회전 시킨 결과들을 따로 저장
    }
    
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            bomb[i][j] = state(0,'W'); // 초기화 과정
    
    memset(visited, false, sizeof(visited));

    dfs(bomb,0);
    
    cout << result << "\n";
    return 0;
}
