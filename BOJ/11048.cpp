#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
int d[1001][1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    d[1][1] = arr[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = max({d[i-1][j-1], d[i-1][j], d[i][j-1]}) + arr[i][j];
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}