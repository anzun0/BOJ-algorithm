#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000;

int n, d[105][10];

int main(void) {
    
    cin >> n;
    for (int i=1; i<10; i++) {
        d[1][i] = 1;
    }
    
    for (int i=2; i<=n; i++) {
        d[i][0] = d[i-1][1];
        d[i][9] = d[i-1][8];
        for (int j=1; j<9; j++) {
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % MOD;
        }
    }
    int ans = 0;
    for (int i=0; i<10; i++) {
        ans = (ans + d[n][i]) % MOD;
    }
    cout << ans << '\n';
}
