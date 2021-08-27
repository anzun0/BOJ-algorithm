#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

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

    int start = 0, end = 1e9;
    int result = 0;
    while(start <= end) {
        long long total = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) total += (arr[i] - mid);
        }
        if (total < m) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
    }
    cout << result << '\n';
    return 0;
}