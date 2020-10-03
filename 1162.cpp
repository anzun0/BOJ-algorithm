#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define INF LLONG_MAX
typedef long long ll;

int N, M, K;
vector<pair<ll, ll> > adj[10001];

vector<vector<ll>> dijkstra(int src)
{
    priority_queue< pair<ll, pair<ll, ll>> > pq; // pq에는 비용,<정점, 남은 포장 가능 횟수>
    vector<vector<ll> > dist(10001, vector<ll>(21, INF));

    dist[src][K] = 0;
    pq.push(make_pair(0, make_pair(src, K)));

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll cur = pq.top().second.first;
        ll k = pq.top().second.second;

        pq.pop();
        
        if (dist[cur][k] < cost) continue;

        for (int i = 0; i < adj[cur].size(); i++)
        {
            ll there = adj[cur][i].first;
            ll nextDist = cost + adj[cur][i].second;

            if (dist[there][k] > nextDist)
            {
                dist[there][k] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(there, k)));
            } // 포장을 더 이상 할 수 없는 경우

            if (k > 0 && (dist[there][k - 1] > cost))
            {
                dist[there][k - 1] = cost;
                pq.push(make_pair(-cost, make_pair(there, k - 1)));
            } // 포장이 가능한 경우
        }
    }
    return dist;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    ll a, b, val;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> val;
        adj[a].push_back(make_pair(b, val));
        adj[b].push_back(make_pair(a, val));
    }

    vector<vector<ll>> dist = dijkstra(1);

    ll min_time = INF;
    for (int i = 0; i < K; i++)
        min_time = min(min_time, dist[N][i]);

    cout << min_time << '\n';

    return 0;
}
