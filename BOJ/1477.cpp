#include <bits/stdc++.h>
using namespace std;

int n, m, l, result;
vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> l;
    arr.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    arr.push_back(l);
    sort(arr.begin(), arr.end());

    int start = 1;
    int end = l - 1;
    while (start <= end) {
        int mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            int dist = arr[i] - arr[i-1];
            cnt += (dist / mid);
            if (dist % mid == 0) cnt -= 1;
        }

        if (cnt > m) start = mid + 1;
        else end = mid - 1;
    }
    cout << start << '\n';
    return 0;
}