#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    long long result = arr[n-1] * m;
    long long start = 0, end = arr[n-1] * m;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            res += (mid / arr[i]);
        }
        if (res >= m) {
            end = mid - 1;
            result = min(result, mid);
        }
        else start = mid + 1;
    }
    cout << result << '\n';
}