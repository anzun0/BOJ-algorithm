#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        
        x -= 1;
        y -= 1;
        bool ok = false;
        
        for (int k = x; k < (n*m); k += m) {
            if (k % n == y) {
                cout << k + 1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) cout << -1 << '\n';
    }
}
