#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> univ;

struct cmp {
    bool operator()(univ &a, univ &b) {
        return a.second < b.second;
    }
};

int main(void) {
    int n;
    priority_queue<univ, vector<univ>, cmp> pq;

    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        pq.push(make_pair(p, d));
    }
    
    while(!pq.empty()) {
        cout << pq.top().second << ' ';
        pq.pop();
    }
}