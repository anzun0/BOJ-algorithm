#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k, m;
    cin >> n >> k >> m;

    deque<int> dq;
    queue<int> result;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int cnt = 1;
    int reverseCount = 0;
    bool reverse = false;

    while (!dq.empty()) {
        int num1 = dq.front();
        int num2 = dq.back();

        if (cnt == k) {
            dq.pop_front();
            result.push(num1);
            reverseCount++;
            if (reverseCount % m == 0)
                reverse = !reverse;
            cnt = reverse ? 0 : 1;
            continue;
        }

        if (reverse) {
            dq.pop_back();
            dq.push_front(num2);
            cnt += 1;
        }
        else {
            dq.pop_front();
            dq.push_back(num1);
            cnt += 1;
        }
    }

    while (!result.empty()) {
        cout << result.front() << '\n';
        result.pop();
    }
}