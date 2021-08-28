#include <bits/stdc++.h>
using namespace std;

int n, c, result;
vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int start = 1;
    int end = arr[n-1] - arr[0];
    while(start <= end) {
        int mid = (start + end) / 2;

        int value = arr[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= value + mid) {
                value = arr[i];
                cnt += 1;
            }
        }

        if (cnt >= c) {
            start = mid + 1;
            result = mid;
        }
        else {
            end = mid -1;
        }
    }
    cout << result << '\n';
}