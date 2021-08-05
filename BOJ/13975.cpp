#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int k;
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            pq.push(val);
        }

        ll sum = 0;
        while (pq.size() > 1) {
            ll num1 = pq.top();
            pq.pop();
            ll num2 = pq.top();
            pq.pop();

            pq.push(num1 + num2);
            sum += (num1 + num2);
        }
        cout << sum << '\n';
    }
}