#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    queue<int> result;

    for (int i = 1; i <= n; i++)
        q.push(i);

    int cnt = 1;
    while (!q.empty()) {
        if (cnt == k) {
            int num = q.front();
            result.push(num);
            q.pop();
            cnt = 1;
        }
        else {
            int num = q.front();
            q.push(num);
            q.pop();
            cnt += 1;
        }
    }

    cout << "<";
    while(!result.empty()) {
        cout << result.front();
        if (result.size() == 1)
            break;
        cout << ", ";
        result.pop();
    }
    cout << ">";
}