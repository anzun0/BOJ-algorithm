#include <bits/stdc++.h>
using namespace std;
int n, c, ans;
int h[200001];

bool install(int dist) {
    int cnt = 1;
    int prev = h[0];
    for(int i = 1; i < n; i++)
        if (h[i] - prev >= dist){
            cnt++;
            prev = h[i];
        }
    if (cnt >= c) return true;
    else return false;
}

int main(void) {
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n);
    
    int st = 1;
    int ed = h[n-1] - h[0];
    while (st <= ed) {
        int mid = (st + ed) / 2;
        if (install(mid)) {
            st = mid + 1;
            ans = max(ans, mid);
        }
        else
            ed = mid - 1;
    }
    cout << ans << '\n';
}
