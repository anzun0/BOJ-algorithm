#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, k;
int s, x, y;
int arr[201][201];
bool visited[201][201];
queue<pair<int, int>> q;

void dfs(int time) {
    if (time == s + 1) {
        cout << arr[x][y] << '\n';
        return;
    }

    int qSize = q.size();
    for (int i = 0; i < qSize; i++) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > n || visited[nx][ny]) continue;
            arr[nx][ny] = arr[cur.X][cur.Y];
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    time += 1;
    dfs(time);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (arr[j][k] == i) {
                    q.push({j, k});
                    visited[j][k] = 1;
                }

    cin >> s >> x >> y;
    dfs(1);
    return 0;
}