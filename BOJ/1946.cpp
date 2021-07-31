#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(void) {
    
    int t;
    cin >> t;
    
    for (int tc = 0; tc < t; tc++) {
        
        int n, ans = 1;
        vector<pii> v;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int score1, score2;
            cin >> score1 >> score2;
            
            v.push_back(pii(score1, score2));
        }
        sort(v.begin(), v.end());
        int score2Rank = v[0].second;
        
        for (int i = 1; i < n; i++) {
            
            if(v[i].second < score2Rank) {
                ans++;
                score2Rank = v[i].second;
            }
        }
        cout << ans << '\n';
    }
}
