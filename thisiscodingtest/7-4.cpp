#include <bits/stdc++.h>
using namespace std;

int n;
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

    int result = -1;
    int start = 0;
    int end = n - 1;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == mid) {
            result = mid;
            break;
        }
        if (arr[mid] > mid) end = mid - 1;
        else start = mid + 1;
    }
    cout << result << '\n';
}