#include <bits/stdc++.h>
using namespace std;

int n;
int d[10000];
vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    d[0] = arr[0];
    d[1] = max(arr[0], arr[1]);
    for (int i = 2; i <= n; i++) {
        d[i] = max(d[i-2] + arr[i], d[i-1]);
    }
    cout << d[n-1] << '\n';
}