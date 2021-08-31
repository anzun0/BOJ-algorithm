#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100][100];
long long d[100][100];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) continue;

            if (i + arr[i][j] < n) {
                d[i+arr[i][j]][j] += d[i][j];
            }

            if (j + arr[i][j] < n) {
                d[i][j+arr[i][j]] += d[i][j];
            }
        }
    }
    cout << d[n-1][n-1] << '\n';
    return 0;
}