#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> arr;

int countByRange(vector<int>& v, int left, int right) {
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), right);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), left);
    return rightIndex - leftIndex;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int cnt = countByRange(arr, x, x);

    if (cnt == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << cnt << '\n';
    }


}