#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int m;
        cin >> m;
        priority_queue<int> maxHeap; // 중앙값보다 작은 수
        priority_queue<int, vector<int>, greater<int>> minHeap; // 중앙값보다 큰 수
        vector<int> result;

        int cnt = 0;

        for (int i = 1; i <= m; i++) {
            int val;
            cin >> val;

            if (maxHeap.empty() && minHeap.empty())
                maxHeap.push(val);
            else if (maxHeap.size() == minHeap.size())
                maxHeap.push(val);
            else
                minHeap.push(val);

            if (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
                int num1 = maxHeap.top();
                int num2 = minHeap.top();

                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(num2);
                minHeap.push(num1);
            }

            if (i % 2 != 0) {
                cnt += 1;
                result.push_back(maxHeap.top());
                continue;
            }
        }
        cout << cnt << '\n';
        for (auto res: result) {
            cout << res << ' ';
        }
        cout << '\n';
    }
}