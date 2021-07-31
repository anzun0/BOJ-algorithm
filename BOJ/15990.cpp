#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000009
int n, t;
ll d[100001][4];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
                
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) {
                d[i][1] = d[i-1][2] + d[i-1][3];
                if (i == 1) d[i][1] = 1;
            }
            if (i - 2 >= 0) {
                d[i][2] = d[i-2][1] + d[i-2][3];
                if (i == 2) d[i][2] = 1;
            }
            if (i - 3 >= 0) {
                d[i][3] = d[i-3][1] + d[i-3][2];
                if (i == 3) d[i][3] = 1;
            }
            d[i][1] %= mod;
            d[i][2] %= mod;
            d[i][3] %= mod;
        }
        ll ans = (d[n][1] + d[n][2] + d[n][3]) % mod;
        cout << ans << '\n';
    }
}
