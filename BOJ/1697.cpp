#include <bits/stdc++.h>
using namespace std;

int n, k;
int dis[100001];
queue<int> Q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(dis, -1, sizeof(dis));
    cin >> n >> k;
    Q.push(n);
    dis[n] = 0;
    
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (auto next : {cur - 1, cur + 1, cur * 2})
        {
            if (next < 0 || next > 100000 || dis[next] != -1) continue;
            Q.push(next);
            dis[next] = dis[cur] + 1;
        }
    }
    cout << dis[k] << '\n';
}
