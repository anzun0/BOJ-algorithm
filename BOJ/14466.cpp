#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int y;
    int x;
    Pos(int a, int b) {y = a; x = b;}
};
struct Cow {
    int y;
    int x;
};

int n, k, r;
int maps[110][110];
int visit[110][110];
vector<Pos> bridge[110][110]; // y, x에 다리로 연결된 목초지의 좌표를 넣어줌
Cow cows[110];
int table[110][110]; // 각 소가 만날 수 있는지 확인 (0: 못만남 1: 만남)
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void BFS(int idx) {
    int y = cows[idx].y;
    int x = cows[idx].x;
    queue<Pos> q;
    q.push(Pos(y, x));
    visit[y][x] = 1;
    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        q.pop();
        // 해당 칸에 소가 있으면 테이블에 기록해준다
        if (maps[y][x] != 0)
            table[idx][maps[y][x]] = 1;
        // 해당 칸에 다리가 하나도 없으면 일반 BFS, 있으면 bridge목록에서 대조후 다리로 연결 안 돼있으면 큐에
        switch (bridge[y][x].empty()) {
        case 1:
            // 그냥 BFS
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {
                    if (visit[ny][nx])
                        continue;
                    visit[ny][nx] = 1;
                    q.push(Pos(ny, nx));
                }
            }
            break;
        case 0:
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                bool isBan = false;
                // 다리가 있는지 확인
                for (int j = 0; j < bridge[y][x].size(); j++) {
                    if (ny == bridge[y][x][j].y && nx == bridge[y][x][j].x)
                        isBan = true;
                }
                if (isBan)
                    continue;
                if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {
                    if (visit[ny][nx])
                        continue;
                    visit[ny][nx] = 1;
                    q.push(Pos(ny, nx));
                }
            }
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> r;
    memset(maps, 0, sizeof(maps));
    memset(table, 0, sizeof(table));
    
    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        bridge[r1][c1].push_back(Pos(r2, c2));
        bridge[r2][c2].push_back(Pos(r1, c1));
    }
    
    for (int i = 1; i <= k; i++) {
        cin >> cows[i].y >> cows[i].x;
        maps[cows[i].y][cows[i].x] = i; // 소의 번호를 맵에 표시
    }
    for (int i = 1; i <= k; i++) {
        memset(visit, 0, sizeof(visit));
        BFS(i);
    }
    
    int result = 0;
    // 테이블의 반만 조회해서 0의 개수를 세어준다
    for (int i = 1; i <= k; i++)
        for (int j = i + 1; j <= k; j++)
            if (table[i][j] == 0) result++;
        
    cout << result <<'\n';
    return 0;
}
