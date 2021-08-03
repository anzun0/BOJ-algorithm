#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;

    while (true) {
        if (n % k == 0) {
            n /= k;
            ans++;
            continue;
        }
        if (n < k) break;
        ans += (n % k);
        n -= (n % k);
    }
    ans += (n - 1);
    cout << ans << '\n';
}