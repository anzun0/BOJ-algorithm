#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        d[i] = d[i-1] + x;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << d[b] - d[a-1] << '\n';
    }
    return 0;
}