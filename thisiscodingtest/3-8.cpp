#include <bits/stdc++.h>
using namespace std;

int n, m, result;
int arr[11];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x] += 1;
    }

    for (int i = 1; i <= m; i++) {
        n -= arr[i];
        result += (arr[i] * n);
    }
    cout << result << '\n';
    return 0;
}