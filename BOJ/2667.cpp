#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
string arr[25];
int vis[25][25]; // 방문 여부를 저장할 배열
queue<pair<int, int>> Q; // bfs에 사용할 큐
vector<int> result; // 단지 별 집의 수를 저장할 벡터

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    fill(&vis[0][0], &vis[n-1][n], -1); // 2차원 배열 vis의 값을 -1로 초기화
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == '1' && vis[i][j] == -1) {
                vis[i][j] = 1;
                Q.push({i, j});
                int count = 1;
                
                while(!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >=n) continue;
                        if (vis[nx][ny] != -1 || arr[nx][ny] == '0') continue;
                        Q.push({nx,ny}); vis[nx][ny] = 1;
                        count++;
                    }
                }
                result.push_back(count);
            }
        }
    }
    sort(result.begin(), result.end());
    auto size = result.size();
    
    cout << size << '\n';
    for(auto i = 0; i < size; i++) cout << result[i] << '\n';
}
