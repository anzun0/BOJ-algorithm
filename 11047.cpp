#include <bits/stdc++.h>
using namespace std;

int main(void) {
    
    int n, k, ans=0;
    vector<int> coin;
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        
        coin.push_back(price);
    }

    for (int i = n - 1; i >= 0; i--) {
        while (k - coin[i] >= 0) {
            ans++;
            k = k - coin[i];
        }
    }
    cout << ans << '\n';
}
