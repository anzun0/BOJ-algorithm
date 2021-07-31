#include <bits/stdc++.h>
using namespace std;
int n, m; // n: 이동하고자 하는 채널, m: 고장난 버튼 수
bool broken[10]; // 고장난 버튼

int check(int t) {
    if (t == 0) {
        if (broken[0]) return 0;
        else return 1;
    }
    00]
    int len = 0;
    while (t > 0) {
        int num = t % 10;
        if (broken[num] == true) return 0;
        t /= 10;
        len += 1;
    }
    return len;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        broken[t] = true;
    }
    
    int ans = n - 100;
    if (ans < 0) ans = -ans;
    
    for (int i = 0; i <= 1000000; i++){
        int len = check(i);
        if (len > 0) {
            int diff = n - i;
            if (diff < 0) diff = -diff;
            ans = min(ans, len + diff);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
