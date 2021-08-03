#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> v(n);
        int zeroCount = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 0) zeroCount++;
        }
        sort(v.begin(), v.end());

        if (zeroCount == 1)
            swap(v[0], v[2]);
        if (zeroCount >= 2) {
            swap(v[0], v[zeroCount]);
            swap(v[1], v[zeroCount+1]);
        }

        int digit = 1, num1 = 0, num2 = 0;
        bool isFirstNum = true;
        for (int i = n-1; i >= 0; i--) {
            if (isFirstNum) {
                num1 += v[i] * digit;
                isFirstNum = false;
                continue;
            }
            num2 += v[i] * digit;
            digit *= 10;
            isFirstNum = true;
        }
        int ans = num1 + num2;
        cout << ans << '\n';
    }
}