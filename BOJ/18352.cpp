#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;
vector<int> graph[300001];
vector<int> d(300001, -1);

void bfs() {
    queue<int> q;
    d[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (d[next] == -1) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }

    bool check = false;
    for (int i = 1; i <= n; i++) {
        if (d[i] == k) {
            cout << i << '\n';
            check = true;
        }
    }
    if (!check) cout << -1 << '\n';
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    bfs();
    return 0;
}