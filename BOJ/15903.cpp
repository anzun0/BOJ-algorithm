#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    
    ll n, m, ans=0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        pq.push(k);
    }
    
    for (int i=0; i<m; i++) {
        ll num1 = pq.top(); pq.pop();
        ll num2 = pq.top(); pq.pop();
        ll sum = num1 + num2;
        pq.push(sum);
        pq.push(sum);
    }
    while(pq.size()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}
