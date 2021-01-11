#include <bits/stdc++.h>
using namespace std;
int n;
int s[10][10];

int main(void) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    
    int ans = -1;
    do {
        int temp = 0;
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            int val = s[v[i]][v[i+1]];
            if (val == 0) {
                ok = false;
                break;
            }
            temp += val;
        }
        if (!ok) continue;
        int val = s[v[n-1]][v[0]];
        if (val == 0) continue;
        temp += val;
        
        if (ans == -1) ans = temp;
        else ans = min(ans, temp);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}
