#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int curTime, direction = 1;
int arr[101][101];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
deque<pair<int, int>> snake;

void turn(char _direction) {
    if (_direction == 'L') {
        direction -= 1;
        if (direction == -1) direction = 3;
    }
    else if (_direction == 'D') {
        direction += 1;
        if (direction == 4) direction = 0;
    }
}

bool check() {
    pair<int, int> beforeHead = snake.front();
    int nx = beforeHead.first + dx[direction];
    int ny = beforeHead.second + dy[direction];

    if (nx < 1 || nx > n || ny < 1 || ny > n) return false;
    if (arr[nx][ny] == -1) return false;

    snake.push_front({nx, ny});
    if (arr[nx][ny] != 1) {
        pair<int, int> beforeTail = snake.back();
        arr[beforeTail.first][beforeTail.second] = 0;
        snake.pop_back();
    }
    arr[nx][ny] = -1;
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }
    snake.push_back({1, 1});
    arr[1][1] = -1; // 뱀이 존재하는 위치를 -1로 설정

    cin >> l;
    for (int i = 0; i < l; i++) {
        int X;
        char C;
        cin >> X >> C;

        while (curTime < X) {
            if (check() == false) {
                cout << curTime + 1 << '\n';
                return 0;
            }
            curTime += 1;
        }
        turn(C);
    }

    while (true) {
        if (check() == false) {
            cout << curTime + 1 << '\n';
            return 0;
        }
        curTime += 1;
    }
}