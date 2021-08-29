#include <bits/stdc++.h>
using namespace std;

int n;
int maxValue;
int d[16];
vector<int> t;
vector<int> p;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int ti, pi;
        cin >> ti >> pi;
        t.push_back(ti);
        p.push_back(pi);
    }

    for (int i = n - 1; i >= 0; i--) {
        int time = t[i] + i;
        if (time <= n) {
            d[i] = max(d[time] + p[i], maxValue);
            maxValue = d[i];
        }
        else d[i] = maxValue;
    }
    cout << maxValue << '\n';
    return 0;
}