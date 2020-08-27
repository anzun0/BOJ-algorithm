#include <bits/stdc++.h>
using namespace std;

int L,C;
char pwd[20];
vector<char> v;
vector<bool> isused;

bool check()
{
    int cons=0, vowel=0;
    for(int i=0;i<L;i++)
    {
        if(pwd[i]=='a' || pwd[i]=='e' || pwd[i]=='i' || pwd[i]=='o' || pwd[i]=='u')
            vowel++;
        else cons++;
    }
    if(cons<2 || vowel<1) return false;
    return true;
}

void func(int k)
{
    if(k==L)
    {
        if(check())
        {
            for(int i=0;i<L;i++)
                cout<<pwd[i];
            cout<<'\n';
            return;
        }
        return;
    }
    for(int i=0;i<v.size();i++)
    {
        if(!isused[i] && pwd[k-1]<=v[i])
        {
            pwd[k]=v[i];
            isused[i]=true;
            func(k+1);
            isused[i]=false;
        }
    }
}

int main(void)
{
    cin>>L>>C;
    for(int i=0;i<C;i++)
    {
        char ch;
        cin>>ch;
        v.push_back(ch);
        isused.push_back(false);
    }
    sort(v.begin(), v.end());
    func(0);
    return 0;
}
