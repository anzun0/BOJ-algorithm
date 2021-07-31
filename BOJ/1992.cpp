#include <bits/stdc++.h>
using namespace std;
int n, arr[64][64];
string str[64];

bool zero(int n, int x, int y)
{
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            if(arr[i][j]==1) return false;
                
    return true;
}
bool one(int n, int x, int y)
{
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            if(arr[i][j]==0) return false;
                
    return true;
}
void func(int n, int x, int y)
{
    if(zero(n,x,y)){
        cout<<0;
        return;
    }
    if(one(n,x,y)){
        cout<<1;
        return;
    }
    cout<<"(";
    func(n/2, x, y);
    func(n/2, x, y+n/2);
    func(n/2, x+n/2, y);
    func(n/2, x+n/2, y+n/2);
    cout<<")";
    
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>str[i];
        for(int j=0;j<n;j++)
            arr[i][j] = str[i][j] - '0';
    }
    
    func(n,0,0);
    return 0;
}
