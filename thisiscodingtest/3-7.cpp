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
    sort(arr.begin(), arr.end());

    int target = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > target) break;
        target += arr[i];
    }
    cout << target << '\n';
    return 0;
}