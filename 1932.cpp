#include <bits/stdc++.h>
using namespace std;
int n, ans;
int d[500][500]; // DP memoization
int s[500][500]; // triangle

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> s[i][j];
    
    d[0][0] = s[0][0]; // 0층
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) // 가장 좌측
                d[i][j] = d[i-1][j] + s[i][j];
            else if (j == i) // 가장 우측
                d[i][j] = d[i-1][j-1] + s[i][j];
            else
                d[i][j] = max({d[i-1][j], d[i-1][j-1]}) + s[i][j];
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans << '\n';
}
