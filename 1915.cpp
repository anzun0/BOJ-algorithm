#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
string a[1000];
int d[1000][1000];

int main(void ) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0)
                d[i][j] = a[i][j] - '0';
            
            else if (a[i][j] == '1') { // 1 경우에만 검사
                int temp = min({d[i-1][j], d[i-1][j-1], d[i][j-1]});
                d[i][j] = temp + 1;
            }
            ans = max(ans, d[i][j]);
        }
    }
    cout << pow(ans, 2) << '\n';
}
