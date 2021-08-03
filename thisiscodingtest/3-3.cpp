#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, result = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int minVal = 10001;
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            minVal = min(minVal, val);
        }
        result = max(result, minVal);
    }
    cout << result << '\n';
}