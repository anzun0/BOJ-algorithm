#include <bits/stdc++.h>
using namespace std;
int d[1005];

int main(void){
    int n;
    cin >> n;
    
    d[1] = 1;
    d[2] = 2;
    for(int k=3;k<=n;k++)
        d[k] = (d[k-1] + d[k-2]) % 10007;
    
    cout << d[n];
}
