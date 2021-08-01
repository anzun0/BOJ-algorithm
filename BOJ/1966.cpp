#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        int n, m, result = 1;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            q.push({ num, i });
            pq.push(num);
        }

        while(!q.empty()) {
            int num = q.front().first;
            int index = q.front().second;

            q.pop();
            q.push({ num, index });
            if (num == pq.top()) {
                if (index == m) {
                    cout << result << '\n';
                    break;
                }
                pq.pop();
                result++;
            }
        }
    }
}