#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    cout << v[(n - 1) / 2] << '\n';
    return 0;
}