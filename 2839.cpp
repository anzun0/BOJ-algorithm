#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> d(n+1, 9999);
    
    d[3] = 1;
    d[5] = 1;
    for(int i=6;i<=n;i++){
        d[i] = min(d[i-5] + 1, d[i-3] + 1);
    }
    
    if (d[n]==9999 || d[n]==10000) {
        cout << -1 << '\n';
    } else {
        cout << d[n] << '\n';
    }
}
