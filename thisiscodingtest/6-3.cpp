#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, b;

bool compare (int a, int b) {
    return a > b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compare);

    for (int i = 0; i < k; i++) {
        if (a[i] < b[i]) swap(a[i], b[i]);
        else break;
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    cout << result << '\n';
    return 0;
}