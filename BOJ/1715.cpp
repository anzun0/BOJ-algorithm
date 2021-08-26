#include <bits/stdc++.h>
using namespace std;

int n, result;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while(true) {
        if (pq.size() == 1) break;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b);
        result += (a + b);
    }
    cout << result << '\n';
    return 0;
}