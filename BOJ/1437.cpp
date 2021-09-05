#include <bits/stdc++.h>
using namespace std;
#define MOD 10007

int n, ans=1;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n >= 5) {
        n -= 3;
        ans = (ans * 3) % MOD;
    }
    cout << (ans * n) % MOD << '\n';
}