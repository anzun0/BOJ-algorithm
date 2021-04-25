#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    stack< pair<int, int> > s;
    vector<int> result;
    
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        
        if (s.empty()) {
            s.push(make_pair(height, i));
            result.push_back(0);
        }
        else {
            while (!s.empty()) {
                if (s.top().first < height) {
                    s.pop();
                    if (s.empty()){
                        result.push_back(0);
                    }
                    continue;
                }
                else {
                    result.push_back(s.top().second);
                    break;
                }
            }
        }
        s.push(make_pair(height, i));
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}