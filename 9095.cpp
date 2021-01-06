#include <bits/stdc++.h>
using namespace std;
int t;
int d[11];

int main(void) {
    cin >> t;
    for (int tc = 0; tc< t; tc++) {
        int n;
        cin >> n;
        
        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        for (int i = 4; i <= n; i++)
            d[i] = d[i-1] + d[i-2] + d[i-3];
        cout << d[n] << '\n';
    }
}
