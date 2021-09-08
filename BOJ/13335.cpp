#include <bits/stdc++.h>
using namespace std;

int n, w, l;
queue<int> t;
queue<pair<int, int>> b;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t.push(x);
    }

    int cnt = 0, weight = 0, curTime = 0;
    while (cnt < n) {
        curTime += 1;

        if (!b.empty() && b.front().second == curTime) {
            weight -= b.front().first;
            cnt += 1;
            b.pop();
        }

        if (!t.empty() && weight + t.front() <= l) {
            b.push({t.front(), curTime + w});
            weight += t.front();
            t.pop();
        }
    }
    cout << curTime << '\n';
}