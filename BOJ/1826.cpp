#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, destination, oil, ans = 0;
    pair<int, int> station[10000];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> station[i].first >> station[i].second;
    cin >> destination >> oil;

    sort(station, station+n);

    int index = 0;
    priority_queue<int> pq;

    while (oil < destination) {
        while (index < n && station[index].first <= oil)
            pq.push(station[index++].second);
        if (pq.empty()) {
            ans = -1;
            break;
        }
        oil += pq.top();
        pq.pop();
        ans += 1;
    }
    cout << ans << '\n';
}