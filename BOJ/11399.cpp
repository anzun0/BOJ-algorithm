#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            ans += v[j];

    cout << ans << '\n';
}