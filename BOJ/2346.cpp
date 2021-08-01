#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    deque<pair<int, int>> dq;
    queue<int> result;

    for (int index = 1; index <= n; index++) {
        int k;
        cin >> k;
        dq.push_back({index, k});
    }

    while (!dq.empty()) {
        int index = dq.front().first;
        int num = dq.front().second;
        result.push(index);

        dq.pop_front();

        if (num > 0) {
            num--;
            while (num--) {
                pair<int, int> pii = dq.front();
                dq.push_back(pii);
                dq.pop_front();
            }
        }
        else {
            num = abs(num);
            while (num--) {
                pair<int, int> pii = dq.back();
                dq.push_front(pii);
                dq.pop_back();
            }
        }
    }
    while (!result.empty()) {
        cout << result.front() << ' ';
        result.pop();
    }
}