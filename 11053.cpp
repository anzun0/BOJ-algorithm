#include <bits/stdc++.h>
using namespace std;
int n, d[1005], s[1005];

int main(void){
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    
    d[0] = 1;
    for(int i=1;i<n;i++){
        d[i] = 1;
        for(int j=0;j<i;j++)
            if(s[j] < s[i]) d[i] = max(d[i], d[j] + 1);
    }
    cout << *max_element(d, d+n)<< '\n';
}
