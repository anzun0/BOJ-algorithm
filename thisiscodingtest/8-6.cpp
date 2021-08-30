#include <bits/stdc++.h>
using namespace std;

int n;
int d[100];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int i2 = 0, i3 = 0, i5 = 0;
    int n2 = 2, n3 = 3, n5 = 5;

    d[0] = 1;
    for (int i = 1; i < n; i++) {
        d[i] = min({n2, n3, n5});

        if (d[i] == n2) {
            i2 += 1;
            n2 = d[i2] * 2;
        }
        if (d[i] == n3) {
            i3 += 1;
            n3 = d[i3] * 3;
        }
        if (d[i] == n5) {
            i5 += 1;
            n5 = d[i5] * 5;
        }
    }
    cout << d[n-1] << '\n';
    return 0;
}