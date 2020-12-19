#include <bits/stdc++.h>
using namespace std;
int n, d[100005][2], s[100005];

int main(void){
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    
    d[0][0] = s[0];
    d[0][1] = s[0];
    
    int result = max(d[0][0], d[0][1]);
    
    for(int i=1;i<n;i++){
        d[i][0] = s[i];
        d[i][1] = max(d[i-1][0], d[i-1][1]) + s[i];
        int temp = max(d[i][0], d[i][1]);
        if(result<temp) result = temp;
    }
    cout << result << '\n';
}
