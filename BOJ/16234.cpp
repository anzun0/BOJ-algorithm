#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, l, r;
int result;
int arr[50][50];
bool visited[50][50];
queue<pair<int, int>> q;

int bfs() {
    int sum = 0;
    queue<pair<int, int>> united;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        united.push(cur);
        sum += arr[cur.X][cur.Y];
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;

            int diff = abs(arr[cur.X][cur.Y] - arr[nx][ny]);
            if (diff < l || diff > r) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    int size = united.size();
    while(!united.empty()) {
        auto cur = united.front(); united.pop();
        arr[cur.X][cur.Y] = sum / size;
    }
    return size;
}

bool transfer() {
    bool flag = false;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!visited[x][y]) {
                q.push({x, y});
                visited[x][y] = 1;
                if (bfs() > 1) flag = true;
            }
        }
    }
    return flag;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    while(true) {
        if (transfer()) {
            result += 1;
            memset(visited, false, sizeof(visited));
        }
        else break;
    }
    cout << result << '\n';
    return 0;
}