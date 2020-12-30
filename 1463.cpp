#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> d(n+1);
    
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    for(int i = 4; i <= n; i++) {
        d[i] = d[i-1] + 1;
        if (i % 3 == 0)
            d[i] = min(d[i], d[i/3] + 1);
        else if (i % 2 == 0)
            d[i] = min(d[i], d[i/2] + 1);
    }
    cout << d[n] << '\n';
}
