#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int arr[21][21];
vector<vector<int>> s(401, vector<int>(4));

int checkLikeStudent(int idx, int x, int y) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        for (int j = 0; j < 4; j++) {
            if (arr[nx][ny] == s[idx][j]) {
                count += 1;
                break;
            }
        }
    }
    return count;
}

int checkEmptyCount(int x, int y) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (arr[nx][ny] == 0) count += 1;
    }
    return count;
}

int checkSatisfication() {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int temp = checkLikeStudent(arr[i][j], i, j);
            if (temp == 1) result += 1;
            if (temp == 2) result += 10;
            if (temp == 3) result += 100;
            if (temp == 4) result += 1000;
        }
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    queue<int> q;

    for (int i = 0; i < n * n; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        q.push(a);
        s[a] = {b, c, d, e};
    }

    while (!q.empty()) {
        int now = q.front(); q.pop();
        pair<int, int> pos = {1e9, 1e9};
        int likeCount = 0, emptyCount = 0;

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] != 0) continue; // 이미 앉은 자리

                int tempLike = checkLikeStudent(now, j, k);
                int tempEmpty = checkEmptyCount(j, k);

                if (likeCount < tempLike) {
                    pos = {j, k};
                    likeCount = tempLike;
                    emptyCount = tempEmpty;
                }
                if (likeCount == tempLike) {
                    if (emptyCount < tempEmpty) {
                        pos = {j ,k};
                        emptyCount = tempEmpty;
                    }
                    if (emptyCount == tempEmpty) {
                        if (pos.first > j || (pos.first == j && pos.second > k)) {
                            pos = {j, k};
                        }
                    }
                }
            }
        }
        arr[pos.first][pos.second] = now;
    }
    cout << checkSatisfication() << '\n';
}