#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, ans=1;
        cin >> n;
        priority_queue<ll> pq;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            pq.push(-x);
        }

        while(pq.size() > 1) {
            ll num1 = -pq.top(); pq.pop();
            ll num2 = -pq.top(); pq.pop();
            ll mul = (num1 * num2);
            pq.push(-mul);
            ans = ans * (mul % MOD) % MOD;
        }
        cout << ans % MOD << '\n';
    }
}