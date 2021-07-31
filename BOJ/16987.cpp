#include <bits/stdc++.h>
using namespace std;

typedef struct info
{
    int w;
    int d;
}info;

info temp;
vector<info> v;
int N = 0, MAX = 0;

int chk()
{
    int ret = 0;
    
    for (int i = 0; i < v.size(); i++)
        if (v.at(i).d <= 0)
            ++ret;
    
    return ret;
}

void simulation(int n)
{
    if (n == N)
    {
        MAX = max(MAX, chk());
        return;
    }
    
    if (v.at(n).d <= 0)
    {
        simulation(n + 1);
        return;
    }
    
    bool go = true;
    for (int i = 0; i < v.size(); i++)
    {
        if (n == i || v.at(i).d <= 0) continue;
        
        v.at(n).d -= v.at(i).w;
        v.at(i).d -= v.at(n).w;
        
        go = false;
        simulation(n + 1);
        
        v.at(n).d += v.at(i).w;
        v.at(i).d += v.at(n).w;
    }
    if (go) simulation(n + 1);
}

int main(void)
{
    int w = 0, d = 0;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &d, &w);
        temp.d = d; temp.w = w;
        v.push_back(temp);
    }
    
    simulation(0);
    printf("%d\n", MAX);
    return 0;
}
