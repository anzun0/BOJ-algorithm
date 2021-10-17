#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int n, m, h;
int result = MAX;
bool link[11][30];

bool check() {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 1; j <= h; j++) {
            if (link[cur][j]) cur = cur + 1;
            else if (link[cur-1][j]) cur = cur - 1;
        }
        if (cur != i) return false;
    }
    return true;
}

void Set_Link(int idx, int cnt) {
    if (cnt >= 4) return;
    if (check()) {
        result = min(result, cnt);
        return;
    }

    for (int i = idx; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (link[j][i]) continue;
            if (link[j-1][i]) continue;
            if (link[j+1][i]) continue;

            link[j][i] = true;
            Set_Link(i, cnt + 1);
            link[j][i] = false;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        link[b][a] = true; // b번과 b+1번을, a번째 가로선을 통해 연결
    }
    Set_Link(1, 0);

    if (result == MAX) result = -1;
    cout << result << '\n';
}