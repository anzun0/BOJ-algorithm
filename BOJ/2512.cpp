#include <bits/stdc++.h>
using namespace std;

int n, m, result;
int maxValue;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        maxValue = max(maxValue, x);
    }
    cin >> m;

    int left = 1;
    int right = maxValue;
    while (left <= right) {
        int mid = (left + right) / 2;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= mid) sum += v[i];
            else sum += mid;
        }

        if (sum <= m) {
            result = max(result, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << result << '\n';
}