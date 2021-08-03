#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap; // 중앙값보다 큰 수
    priority_queue<int> maxHeap; // 중앙값보다 작은 수

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (maxHeap.empty() && minHeap.empty())
            maxHeap.push(num);
        else if (maxHeap.size() == minHeap.size())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
            int num1 = maxHeap.top();
            int num2 = minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            minHeap.push(num1);
            maxHeap.push(num2);
        }

        cout << maxHeap.top() << '\n';
    }
}