#include <bits/stdc++.h>
using namespace std;

int n, result=1e9;
string st, dt, temp;

void flip(int idx) {
    temp[idx-1] = (temp[idx-1] == '0') ? '1' : '0';
    temp[idx] = (temp[idx] == '0') ? '1' : '0';
    if (idx < n - 1) {
        temp[idx+1] = (temp[idx+1] == '0') ? '1' : '0';
    }
}

int main(void) {
    cin >> n;
    cin >> st >> dt;

    // 0번 스위치를 누르는 경우
    temp = st;
    int cnt = 0;
    temp[0] = (temp[0] == '0') ? '1' : '0';
    temp[1] = (temp[1] == '0') ? '1' : '0';
    cnt += 1;
    for (int i = 1; i < n; i++) {
        if (temp[i-1] != dt[i-1]) {
            flip(i);
            cnt += 1;
        }
    }
    if (temp == dt) result = min(result, cnt);

    // 다시 초기화
    temp = st;
    cnt = 0;

    // 0번 스위치를 누르지 않는 경우
    for (int i = 1; i < n; i++) {
        if (temp[i-1] != dt[i-1]) {
            flip(i);
            cnt += 1;
        }
    }
    if (temp == dt) result = min(result, cnt);

    if (result != 1e9) cout << result << '\n';
    else cout << -1 << '\n';
}