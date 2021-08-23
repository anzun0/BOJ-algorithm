#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
string result = "NO";
char arr[6][6];

bool checkGraph() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 'T')
                q.push({i, j});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = cur.X - 1; i >= 0; i--) {
            if (arr[i][cur.Y] == 'O') break;
            if (arr[i][cur.Y] == 'S') return false;
        }
        for (int i = cur.X + 1; i < n; i++) {
            if (arr[i][cur.Y] == 'O') break;
            if (arr[i][cur.Y] == 'S') return false;
        }
        for (int i = cur.Y - 1; i >= 0; i--) {
            if (arr[cur.X][i] == 'O') break;
            if (arr[cur.X][i] == 'S') return false;
        }
        for (int i = cur.Y + 1; i < n; i++) {
            if (arr[cur.X][i] == 'O') break;
            if (arr[cur.X][i] == 'S') return false;
        }
    }
    return true;
}

void dfs(int count) {
    if (count == 3) {
        if (checkGraph()) result = "YES";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'X') {
                arr[i][j] = 'O';
                count += 1;
                dfs(count);
                arr[i][j] = 'X';
                count -= 1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    dfs(0);
    cout << result << '\n';
    return 0;
}