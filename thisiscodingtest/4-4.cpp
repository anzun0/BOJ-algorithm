#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y, direction;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int d[50][50];   // 방문여부 확인
int arr[50][50]; // 전체 맵 정보

void turn_left() {
    direction -= 1;
    if (direction == -1) direction = 3;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> x >> y >> direction;
    d[x][y] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    int cnt = 1; // 결과
    int turn_time = 0;
    while (true) {
        turn_left();
        int nx = x + dx[direction];
        int ny = y + dx[direction];

        if (d[nx][ny] == 0 && arr[nx][ny] == 0) {
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        }
        else turn_time += 1;

        if (turn_time == 4) {
            nx = x - dx[direction];
            ny = y - dy[direction];
            if (arr[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            else break;
            turn_time = 0;
        }
    }
    cout << cnt << '\n';
}