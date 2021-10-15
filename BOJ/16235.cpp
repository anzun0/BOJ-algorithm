#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[11][11];

int yang[11][11]; // 땅에 있는 양분
vector<int> tree[11][11]; // 해당 좌표에 위치한 나무들의 나이

void SpringAndSummer() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int deadTrees = 0;
            vector<int> live;

            // 봄
            sort(tree[i][j].begin(), tree[i][j].end());

            for (int t = 0; t < tree[i][j].size(); t++) {
                int age = tree[i][j][t];

                if (yang[i][j] < age) deadTrees += (age / 2);
                else {
                    live.push_back(age + 1);
                    yang[i][j] -= age;
                }
            }
            tree[i][j].clear();
            tree[i][j] = live;

            // 여름
            yang[i][j] += deadTrees;
        }
    }
}

void spread(int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (x + i < 1 || x + i > n || y + j < 1 || y + j > n) continue;

            tree[x+i][y+j].push_back(1);
        }
    }
}

void AutumnAndWinter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 가을
            for (int t = 0; t < tree[i][j].size(); t++) {
                int age = tree[i][j][t];
                if (age % 5 == 0) spread(i, j);
            }
            // 겨울
            yang[i][j] += a[i][j];
        }
    }
}

int getResult() {
    int result = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            result += tree[i][j].size();

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            yang[i][j] = 5;
        }
    }

    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    while (k--) {
        SpringAndSummer();
        AutumnAndWinter();
    }
    cout << getResult() << '\n';
}