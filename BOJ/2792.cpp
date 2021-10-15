#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long maxValue, result=1e9;
long long arr[300000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        maxValue = max(maxValue, arr[i]);
    }

    long long left = 1, right = maxValue;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long temp = 0;

        for (int i = 0; i < m; i++) {
         temp += (arr[i] / mid);
         if (arr[i] % mid != 0)
             temp += 1;
        }

        if (temp <= n) {
            right = mid - 1;
            result = min(result, mid);
        }
        else {
            left = mid + 1;
        }
    }
    cout << result << '\n';
}