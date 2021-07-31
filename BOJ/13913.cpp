#include <bits/stdc++.h>
using namespace std;
int N, K;
int dist[100001], parent[100001];
vector<int> path;

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
            parent[next]=cur;
        }
    }
    path.push_back(K);
    int idx=K;
    while(idx!=N){
        path.push_back(parent[idx]);
        idx=parent[idx];
    }
    cout << dist[K]<<'\n';
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    
    return 0;
}

