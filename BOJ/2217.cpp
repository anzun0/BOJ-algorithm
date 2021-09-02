#include <bits/stdc++.h>
using namespace std;

int n, result;
priority_queue<int> pq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int count = 1;
    while (!pq.empty()) {
        int temp = count * pq.top();
        pq.pop();
        count += 1;
        result = max(result, temp);
    }
    cout << result << '\n';
}