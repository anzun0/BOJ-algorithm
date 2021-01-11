#include <bits/stdc++.h>
using namespace std;
int n;
int d[1001], pre[1001], v[1001];

void go(int p) {
    if (p == -1) return;
    go(pre[p]);
    cout << v[p] << ' ';
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        d[i] = 1;
        pre[i] = -1;
        for (int j = 1; j < i; j++)
            if (v[j] < v[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                pre[i] = j;
            }
    }
    
    int ans = d[1];
    int p = 1;
    for (int i = 1; i <= n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }
    cout << ans << '\n';
    go(p);
    cout << '\n';
}

