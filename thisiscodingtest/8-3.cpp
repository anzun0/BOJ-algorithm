#include <bits/stdc++.h>
using namespace std;

int n;
int d[1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + 2 * d[i-2]) % 796796;
    }
    cout << d[n] << '\n';
}