#include <bits/stdc++.h>
using namespace std;
int n, ans;
int d[200], s[200];
bool moved[200];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    
    d[0] = s[0];
    int max_value = s[0], min_value = s[0];
    int max_index = 0, min_index = 0;
    
    for (int i = 1; i < n; i++) {
        if (s[i] < max_value && !moved[max_index]) {
            moved[max_index] = true;
            ans++;
        }
        else if (s[i] < min_value) {
            moved[i] = true;
            ans++;
            min_value = s[i];
            min_index = i;
        }
        
    }
}
