#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000];

int main(void) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    d[0] = 1;
    for (int i = 1; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[j] < v[i])
                d[i] = max(d[i], d[j] + 1);
    }
    cout << *max_element(d, d + n) << '\n';
}
