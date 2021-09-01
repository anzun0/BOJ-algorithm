#include <bits/stdc++.h>
using namespace std;

int n, result;
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

    int count = 0;
    for (int i = 0; i < n; i++) {
        count += 1;
        if (count >= arr[i]) {
            result += 1;
            count = 0;
        }
    }
    cout << result << '\n';
}