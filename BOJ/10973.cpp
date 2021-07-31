#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    if (prev_permutation(v.begin(), v.end())) {
        for (int i = 0; i < n; i++)
            cout << v[i] << ' ';
    } else {
        cout << -1 << '\n';
    }
}
