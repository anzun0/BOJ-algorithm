#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v, targets;

int binarySearch(vector<int>& v, int target, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (v[mid] == target) return mid;
    else if (v[mid] > target) return binarySearch(v, target, start, mid - 1);
    else return binarySearch(v, target, mid + 1, end);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }

    for (int i = 0; i < m; i++) {
        int result = binarySearch(v, targets[i], 0, n - 1);
        if (result != -1) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }

}