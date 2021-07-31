#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans;
ll tree[1000001];

bool cut(ll height) {
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if (tree[i] - height > 0)
            sum += tree[i] - height;
    }
    if (sum >= m) return true;
    else return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> tree[i];
    
    ll low = 1;
    ll high = *max_element(tree, tree+n);
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (cut(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << '\n';
}
