#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n;
int x, y, d, g;
int arr[101][101];
vector<int> dir;

void make_dragon_curve() {
    int s = dir.size();
    for (int i = s - 1; i >= 0; i--) {
        int nD = (dir[i] + 1) % 4;
        x = x + dx[nD];
        y = y + dy[nD];
        arr[x][y] = 1;

        dir.push_back(nD);
    }
}

void count_square() {
    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) result += 1;
        }
    }
    cout << result << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> y >> x >> d >> g;

        dir.clear();

        arr[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        arr[x][y] = 1;

        dir.push_back(d);
        for (int j = 0; j < g; j++) {
            make_dragon_curve();
        }
    }
    count_square();
}