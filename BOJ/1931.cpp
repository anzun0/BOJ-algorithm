#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        v.push_back({num1, num2});
    }
    sort(v.begin(), v.end(), cmp);

    int now = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first >= now) {
            ans += 1;
            now = v[i].second;
        }
        else continue;
    }
    cout << ans << '\n';
}