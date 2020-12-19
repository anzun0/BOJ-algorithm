#include <bits/stdc++.h>
using namespace std;
int d[305], s[305];

int main(void){
    int n, sum=0, result;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin>>s[i];
        sum += s[i];
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for(int i=4;i<=n;i++){
        d[i] = min(d[i-2], d[i-3]) + s[i];
    }
    
    result = sum - min(d[n-1], d[n-2]);
    cout << result;
}
