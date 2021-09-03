#include <bits/stdc++.h>
using namespace std;

long long n, sum;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }
    sort(v.begin(), v.end());

    long long temp = 0;
    for (int i = 0; i < n; i++) {
        temp += v[i].second;
        if (temp >= (sum + 1) / 2) {
            cout << v[i].first << '\n';
            return 0;
        }
    }
}