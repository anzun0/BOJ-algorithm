#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    priority_queue<int> pq;

    if (k >= n) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++) {
        int diff = v[i] - v[i-1];
        pq.push(diff);
    }

    while (!pq.empty()) {
        if (k > 1) {
            pq.pop();
            k--;
            continue;
        }
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}