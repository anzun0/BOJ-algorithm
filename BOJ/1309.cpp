#include <bits/stdc++.h>
using namespace std;
#define MOD 9901

int n, result;
int d[100000][3];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    d[0][0] = 1;
    d[0][1] = 1;
    d[0][2] = 1;

    for (int i = 1; i < n; i++) {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % MOD;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % MOD;
    }

    result = (d[n-1][0] + d[n-1][1] + d[n-1][2]) % MOD;
    cout << result << '\n';
    return 0;
}