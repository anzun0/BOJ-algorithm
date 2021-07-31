#include <bits/stdc++.h>
using namespace std;

int size[101010];
vector<int> g[101010];

int dfs(int now, int prv){
    size[now] = 1;
    for(auto nxt : g[now]){
        if(prv == nxt) continue;
        size[now] += dfs(nxt, now);
    }
    return size[now];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, r, q; cin >> n >> r >> q;

    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(r, 0);

    while(q--){
        int t; cin >> t;
        cout << size[t] << "\n";
    }
}
