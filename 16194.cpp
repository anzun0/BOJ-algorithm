#include <bits/stdc++.h>
using namespace std;
int n;
int d[1001], p[10001];

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    fill(d, d + n + 1, -1);
    
    d[0] = 0;
    d[1] = p[1];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (d[i] == -1 || d[i] > d[i-j] + p[j])
                d[i] = d[i-j] + p[j];
    cout << d[n] << '\n';
}
