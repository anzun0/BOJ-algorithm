#include <bits/stdc++.h>
using namespace std;

int check(int n, vector<string> &a) {
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (a[i][j-1] == a[i][j]) cnt += 1;
            else cnt = 1;
            ans = max(ans, cnt);
        }
    
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (a[j-1][i] == a[j][i]) cnt += 1;
            else cnt = 1;
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main(void) {
    int n, result = 0;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (j < n - 1) {
                swap(v[i][j], v[i][j+1]);
                int temp = check(n, v);
                result = max(result, temp);
                swap(v[i][j], v[i][j+1]);
            }
            if (i < n - 1) {
                swap(v[i][j], v[i+1][j]);
                int temp = check(n, v);
                result = max(result, temp);
                swap(v[i][j], v[i+1][j]);
            }
        }
    }
    cout << result << '\n';
}
