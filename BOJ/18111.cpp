#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int minTime=1e9, maxHeight;
int arr[500][500];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int h= 0; h <= 256; h++) {
        int build = 0;
        int remove = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int height = arr[i][j] - h;
                if (height > 0) remove += height;
                else if (height < 0) build -= height;
            }
        }
        if (remove + b >= build) {
            int time = 2 * remove + build;
            if (time <= minTime) {
                minTime = time;
                maxHeight = h;
            }
        }
    }
    cout << minTime << ' ' << maxHeight << '\n';
}