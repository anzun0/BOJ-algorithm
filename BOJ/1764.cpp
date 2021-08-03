#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    set<string> s;
    int result = 0;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        s.insert(name);
    }
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        
        if (s.count(name)) {
            result += 1;
            v.push_back(name);
        }
    }
    cout << result << '\n';
    sort(v.begin(), v.end());
    for (auto name: v)
        cout << name << '\n';
}