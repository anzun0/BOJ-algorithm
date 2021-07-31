#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ans; // n: 필요한 랜선의 수, k: 현재 가지고 있는 랜선의 수
ll wire[10001]; // 현재 가지고 있는 랜선의 길이를 저장할 배열

ll cut(ll len) {
    ll count = 0;
    for(int i = 0; i < k; i++)
        count += wire[i] / len;
    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> k >> n;
    for(int i = 0; i < k; i++) cin >> wire[i];
    sort(wire, wire + k);
    
    ll low = 1;
    ll high = *max_element(wire, wire + k);
    while(low<=high) {
        ll mid = (low + high) / 2;
        
        if (cut(mid) >= n) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << '\n';
}
