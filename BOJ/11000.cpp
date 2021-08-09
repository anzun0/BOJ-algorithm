#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        if (v[i].first < pq.top())
            pq.push(v[i].second);
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << pq.size() << '\n';
}