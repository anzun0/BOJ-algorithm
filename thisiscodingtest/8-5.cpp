#include <bits/stdc++.h>
using namespace std;

int n, m, maxValue;
int arr[20][20];
int d[20][20];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                d[i][j] = arr[i][j];
            }
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int left_top, left, left_down;

                if (i == 0) left_top = 0;
                else left_top = d[i-1][j-1];

                left = d[i][j-1];

                if (i == n - 1) left_down = 0;
                else left_down = d[i+1][j-1];

                d[i][j] = max({left_top, left, left_down}) + arr[i][j];
            }
        }

        for (int i = 0; i < n; i++)
            maxValue = max(maxValue, d[i][m-1]);

        cout << maxValue << '\n';
    }
}