#include <bits/stdc++.h>
using namespace std;

int n, h;
int seok[500001], jong[500001];
int d[500001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i % 2 == 0) seok[x] += 1;
        else jong[x] += 1;
    }

    for (int i = h - 2; i >= 1; i--) {
        seok[i] += seok[i+1];
        jong[i] += jong[i+1];
    }

    d[1] = seok[1];
    d[h] = jong[1];
    for (int i = 2; i <= h - 1; i++) {
        d[i] = seok[i] + jong[h+1-i];
    }

    sort(d + 1, d + h + 1);

    cout << d[1] << " ";
    cout << upper_bound(d + 1, d + h + 1, d[1]) - lower_bound(d + 1, d + h + 1, d[1]);
}