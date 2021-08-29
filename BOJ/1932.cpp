#include <bits/stdc++.h>
using namespace std;

int n;
int d[500][500];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> s(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> s[i][j];
        }
    }

    d[0][0] = s[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (d[i-1][j] != -1) d[i][j] = max(d[i][j], d[i-1][j] + s[i][j]);
            if (d[i-1][j-1] != -1) d[i][j] = max(d[i][j], d[i-1][j-1] + s[i][j]);
        }
    }

    int result = *max_element(d[n-1], d[n-1] + n);
    cout << result << '\n';
    return 0;
}