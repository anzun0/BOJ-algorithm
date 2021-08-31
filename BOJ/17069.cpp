#include <bits/stdc++.h>
using namespace std;

int n;
int arr[32][32];
long long dp[3][33][33];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j+1] == 0) dp[0][i][j+1] += (dp[0][i][j] + dp[2][i][j]);
            if (arr[i+1][j] == 0) dp[1][i+1][j] += (dp[1][i][j] + dp[2][i][j]);
            if (arr[i][j+1] == 0 && arr[i+1][j] == 0 && arr[i+1][j+1] == 0)
                dp[2][i+1][j+1] += (dp[0][i][j] + dp[1][i][j] + dp[2][i][j]);
        }
    }
    cout << dp[0][n-1][n-1] + dp[1][n-1][n-1] + dp[2][n-1][n-1] << '\n';
    return 0;
}