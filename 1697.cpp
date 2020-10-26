#include <bits/stdc++.h>
using namespace std;
int N, K, dist[1000001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    queue<int> Q;
    memset(dist, -1, sizeof(dist));

    cin >> N >> K;
    dist[N] = 0; Q.push(N);

    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (auto next : { cur - 1,cur + 1,cur * 2 }) {
            if (next < 0 || next>100000) continue;
            if (dist[next] != -1 ) continue;
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    cout << dist[K];
    return 0;
}
