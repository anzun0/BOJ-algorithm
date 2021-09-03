#include <bits/stdc++.h>
using namespace std;

int n, result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> v(n+2, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = n; i > 1; i--) {
        int j;
        for (j = 1; j <= n; j++) {
            if (v[j] == i) break;
        }
        result += (v[j] - max(v[j-1], v[j+1]));
        for (;j <= n; j++) {
            v[j] = v[j+1];
        }
    }
    cout << result << '\n';
}