#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, M;
vector<pair<int, int> > vec[801];

int dijkstra(int start, int end)
{
    int* distance = new int [N + 1];
    for (int k = 1; k <= N; k++)
    {
        distance[k] = INF;
    }
    priority_queue<pair<int, int> > pr;

    pr.push({ start,0 });
    distance[start] = 0;

    while (!pr.empty())
    {
        int current = pr.top().first;
        int cost = pr.top().second;

        pr.pop();
        if (distance[current] < cost)
            continue;

        for (int i = 0; i < vec[current].size(); i++)
        {
            int next = vec[current][i].first;
            int nextcost = cost + vec[current][i].second;

            if (distance[next] > nextcost)
            {
                pr.push({ next,nextcost });
                distance[next] = nextcost;
            }
        }
    }
    return distance[end];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
    }

    int tos1, tos2;
    cin >> tos1 >> tos2;

    int A = dijkstra(1, tos1) + dijkstra(tos1, tos2) + dijkstra(tos2, N);
    int B = dijkstra(1, tos2) + dijkstra(tos2, tos1) + dijkstra(tos1, N);
    int C = min(A, B);

    if (C >= INF || C < 0)
        cout << "-1" << '\n';
    else
        cout << C << '\n';

    return 0;
}
