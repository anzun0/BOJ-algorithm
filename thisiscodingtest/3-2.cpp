#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int first = v[n-1];
    int second = v[n-2];

    int firstCount = (m / (k + 1)) * k + (m % (k + 1) );
    int secondCount = m - firstCount;

    int ans = first * firstCount + second * secondCount;
    cout << ans << '\n';
}