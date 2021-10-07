#include <bits/stdc++.h>
using namespace std;

int arr[20][20];

int dx[] = {0, 1, 1, 1};
int dy[] = {1, -1, 0, 1};

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

bool check(int x, int y) {
    int color = arr[x][y];

    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> result;
        result.push_back({x, y});
        int tempX = x;
        int tempY = y;
        while (true) {
            int nx = tempX + dx[i];
            int ny = tempY + dy[i];

            if (nx < 1 || nx > 19 || ny < 1 || ny > 19) break;
            if (arr[nx][ny] != color) break;
            result.push_back({nx, ny});
            tempX = nx;
            tempY = ny;
        }
        if (result.size() == 5) {
            int nx = x - dx[i];
            int ny = y - dy[i];
            if (nx < 1 || nx > 19 || ny < 1 || ny > 19 || arr[nx][ny] != color) {
                sort(result.begin(), result.end(), compare);
                cout << color << '\n';
                cout << result[0].first << ' ' <<result[0].second << '\n';
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (arr[i][j] != 0 && check(i, j)) return 0;
        }
    }
    cout << 0 << '\n';
}