#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, result;
int curX, curY;
int curSize=2, toEat = 2;
int arr[20][20];

vector<pair<int, pair<int, int>>> fish;

void bfs(int x, int y) {
    fish.clear();
    queue<pair<int, int>> q;
    q.push({x, y});

    int dist[20][20] = {0};
    int visited[20][20] = {0};
    visited[x][y] = 1;

    int minDist = 1e9;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] || curSize < arr[nx][ny]) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            visited[nx][ny] = 1;
            q.push({nx, ny});

            if (arr[nx][ny] > 0 && curSize > arr[nx][ny]) {
                if (minDist >= dist[nx][ny]) {
                    minDist = dist[nx][ny];
                    fish.push_back({minDist, {nx, ny}});
                }
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                arr[i][j] = 0;
                curX = i;
                curY = j;
            }
        }
    }

    while (true) {
        bfs(curX, curY);
        if (fish.empty()) break;
        else {
            sort(fish.begin(), fish.end());
            result += fish[0].first;

            toEat -= 1;
            if (toEat == 0) {
                curSize += 1;
                toEat = curSize;
            }
            curX = fish[0].second.first;
            curY = fish[0].second.second;
            arr[curX][curY] = 0;
        }
    }
    cout << result << '\n';
}