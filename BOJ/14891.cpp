#include <bits/stdc++.h>
using namespace std;

int k;
deque<int> dq[4];

void rotate(int num, int dir) {
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            int x;
            cin >> x;
            dq[i].push_back(x);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        rotate(num - 1, dir);
    }
}