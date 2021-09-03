#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < 0) cnt += 1;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < cnt; i += m)
        result += abs(v[i] * 2);
    for (int i = n - 1; i >= cnt; i -= m)
        result += (v[i] * 2);

    result -= max(abs(v[0]), abs(v[n-1]));
    cout << result << '\n';
}