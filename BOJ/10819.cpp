#include <bits/stdc++.h>
using namespace std;
int n, ans;

int check(vector<int> &a) {
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        int temp = a[i] - a[i+1];
        if (temp < 0) temp = -temp;
        sum += temp;
    }
    return sum;
}
int main(void) {
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    do {
        ans = max(ans, check(v));
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}
