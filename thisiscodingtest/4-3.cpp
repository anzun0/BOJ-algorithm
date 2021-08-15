#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string inputData;
    cin >> inputData;

    int row = inputData[1] - '0';
    char col = inputData[0] - 'a' + 1;

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];
        if (nextRow >= 1 && nextRow <= 8 && nextCol >= 1 && nextCol <= 8) ans++;
    }
    cout << ans << '\n';
    return 0;
}