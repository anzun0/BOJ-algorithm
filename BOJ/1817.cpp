#include <bits/stdc++.h>
using namespace std;

int n, m, sum, ans = 1;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        sum += v[i];
        if (sum > m) {
            ans += 1;
            sum = v[i];
        }
    }
    cout << ans << '\n';
}