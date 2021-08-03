#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top().second << '\n';
            pq.pop();
        }
        else {
            pq.push({ abs(num), num });
        }
    }
}