#include <bits/stdc++.h>
using namespace std;
int n, k, d[10005], s[105];

int main(void){
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> s[i];
    
    d[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=s[i]; j<=k; j++){
            d[j] += d[j-s[i]];
        }
    }
    cout << d[k]<< '\n';
}
