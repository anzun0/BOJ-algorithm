#include <bits/stdc++.h>
using namespace std;

int n, m, result; // n: 컴퓨터 수, m: 연결 수, result: 결과
int virus[100][100], vis[100];
queue<int> Q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        virus[x][y] = virus[y][x] = 1;
    }
    
    Q.push(1);
    vis[1] = true;
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0 && virus[cur][i] == 1)
            {
                Q.push(i);
                vis[i] = true;
                result++;
            }
        }
    }
    cout << result << '\n';
}
