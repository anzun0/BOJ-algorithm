#include <bits/stdc++.h>
using namespace std;

int x;
int d[30001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x;

    for (int i = 2; i <= x; i++) {
        d[i] = d[i-1] + 1;

        if (i % 5 == 0) {
            d[i] = min(d[i], d[i/5] + 1);
        }
        if (i % 3 == 0) {
            d[i] = min(d[i], d[i/3] + 1);
        }
        if (i % 2 == 0) {
            d[i] = min(d[i], d[i/2] + 1);
        }
    }
    cout << d[x] << '\n';

}