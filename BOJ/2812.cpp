#include <bits/stdc++.h>
using namespace std;

int n, k;
string num;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    cin >> num;

    deque<char> dq;
    for (int i = 0; i < n; i++) {
        while (k > 0 && !dq.empty() && dq.back() < num[i]) {
            dq.pop_back();
            k -= 1;
        }
        dq.push_back(num[i]);
    }
    while (k--) {
        dq.pop_back();
    }
    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
}