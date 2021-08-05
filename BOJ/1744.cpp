#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int> positive;
    priority_queue<int, vector<int>, greater<int>> negative;
    bool zero = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (val > 0) {
            if (val == 1) {
                oneCount += 1;
                continue;
            }
            positive.push(val);
        }
        else if (val < 0) negative.push(val);
        else zero = true;
    }

    int ans = 0;

    while (positive.size() > 1) {
        int num1 = positive.top();
        positive.pop();
        int num2 = positive.top();
        positive.pop();

        ans += (num1 * num2);
    }
    if (positive.size()) ans += positive.top();
    ans += oneCount;

    while (negative.size() > 1) {
        int num1 = negative.top();
        negative.pop();
        int num2 = negative.top();
        negative.pop();

        ans += (num1 * num2);
    }
    if (negative.size() && !zero) ans += negative.top();

    cout << ans << '\n';
}