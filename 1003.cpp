#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> d(41);

int main(void) {
    int t;
    cin >> t;
    d[0] = make_pair(1, 0);
    d[1] = make_pair(0, 1);
    for(int i = 2; i < 41; i++) {
        d[i].first = d[i-1].first + d[i-2].first;
        d[i].second = d[i-1].second + d[i-2].second;
    }
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << d[n].first << ' ' << d[n].second <<'\n';
    }
}
