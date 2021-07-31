#include <bits/stdc++.h>
using namespace std;

int main(void) {
    
    while(1) {
        int k;
        cin >> k;
        if (k == 0) break;
        vector<int> v(k), t(k, 1);
        
        for (int i = 0; i < k; i++) cin >> v[i];
        for (int i = 0; i < 6; i++) t[i] = 0;
        
        do {
            for (int i = 0; i < k; i++)
                if (t[i] == 0) cout << v[i] << ' ';
            cout << '\n';
        } while (next_permutation(t.begin(), t.end()));
        cout << '\n';
    }
}
