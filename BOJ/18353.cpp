#include <bits/stdc++.h>
using namespace std;

int n;
int d[2000];
vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        int x;
        cin >> x;
        arr.push_back(x);
    }

    reverse(arr.begin(), arr.end());

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    int maxValue = *max_element(d, d + n);
    cout << n - maxValue << '\n';
    return 0;
}