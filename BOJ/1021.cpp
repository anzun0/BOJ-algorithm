#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m, result=0;
    cin >> n >> m;

    deque<int> dq;
    queue<int> find;

    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        find.push(num);
    }

    while (!find.empty()) {
        int cnt1 = 0, cnt2 = 1; // 2, 3번 중 더 적은 연산 횟수를 가지는 방법 선택

        deque<int>::iterator iter1 = dq.begin();
        deque<int>::reverse_iterator iter2 = dq.rbegin();

        for (iter1; iter1 != dq.end(); iter1++) {
            if (*iter1 == find.front()) {
                break;
            }
            cnt1 += 1;
        }

        for (iter2; iter2 != dq.rend(); iter2++) {
            if (*iter2 == find.front()) {
                break;
            }
            cnt2 += 1;
        }

        if (cnt1 < cnt2) {
            result += cnt1;
            while (cnt1--) {
                int num = dq.front();
                dq.push_back(num);
                dq.pop_front();
            }
            dq.pop_front();
        }
        else {
            result += cnt2;
            while (cnt2--) {
                int num = dq.back();
                dq.push_front(num);
                dq.pop_back();
            }
            dq.pop_front();
        }
        find.pop();
    }
    cout << result << '\n';
}