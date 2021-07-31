#include <bits/stdc++.h>
using namespace std;
int n;
int d[310][2], s[310];

int main(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    d[1][0] = s[1];
    d[1][1] = 0;
    d[2][0] = s[2];
    d[2][1] = s[1] + s[2];
    
    for(int i = 3; i <= n; i++) {
        d[i][0] = max(d[i-2][0], d[i-2][1]) + s[i];
        d[i][1] = d[i-1][0] + s[i];
    }
    cout << max(d[n][0], d[n][1]) << '\n';
}
