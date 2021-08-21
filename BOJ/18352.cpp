#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;

vector<int> bfs(int k, int start, vector<vector<int>> road) {
    vector<int> result;
    int* visited = new int[n+1];
    for (int i = 1; i <= n; i++) visited[i] = -1;

    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty()) {
        int nx = q.front(); q.pop();

        for (int i = 0; i < road[nx].size(); i++) {
            if (visited[road[nx][i]] == -1) {
                q.push(road[nx][i]);
                visited[road[nx][i]] = visited[nx] + 1;

                if (visited[road[nx][i]] == k)
                    result.push_back(road[nx][i]);
            }
        }
    }
    delete[] visited;
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> x;
    vector<vector<int>> road(n + 1);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        road[from].push_back(to);
    }
    vector<int> result = bfs(k, x, road);
    if (result.empty()) cout << -1 << '\n';
    else {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << '\n';
    }
    return 0;
}