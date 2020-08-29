#include <bits/stdc++.h>
using namespace std;

int k, arr[6];
vector<int> v;
vector<bool> isused;

void func(int idx, int n)
{
    if(n==6)
    {
        for(int i=0;i<6;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=idx;i<k;i++)
    {
        if(!isused[i])
        {
            arr[n]=v[i];
            isused[i]=true;
            func(i, n+1);
            isused[i]=false;
        }
    }
}

int main(void)
{
    while(true)
    {
        cin>>k;
        if(k==0) return 0;
        
        v.clear();
        isused.clear();
        
        for(int i=0;i<k;i++)
        {
            int input;
            cin>>input;
            v.push_back(input);
            isused.push_back(false);
        }
        func(0,0);
        cout<<'\n';
    }
}
